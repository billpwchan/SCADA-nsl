function $addKeyHandlersTo(this$static, source){
  source.addKeyDownHandler(this$static);
  source.addKeyPressHandler(this$static);
  source.addKeyUpHandler(this$static);
}

function HandlesAllKeyEvents(){
}

_ = HandlesAllKeyEvents.prototype = new Object_0;
_.getClass$ = function getClass_135(){
  return Lcom_google_gwt_event_dom_client_HandlesAllKeyEvents_2_classLit;
}
;
_.castableTypeMap$ = makeCastMap([Q$KeyDownHandler, Q$KeyPressHandler, Q$KeyUpHandler, Q$EventHandler]);
function $retainAll(this$static, c){
  var changed, iter;
  iter = this$static.iterator_0();
  changed = false;
  while (iter.hasNext_0()) {
    if (!c.contains_0(iter.next_0())) {
      iter.remove_1();
      changed = true;
    }
  }
  return changed;
}

function $delegateEvent(target, event_0){
  !!target.handlerManager && $fireEvent(target.handlerManager, event_0);
}

_ = FocusWidget.prototype;
_.addKeyDownHandler = function addKeyDownHandler(handler){
  return $addDomHandler(this, handler, ($clinit_KeyDownEvent() , $clinit_KeyDownEvent() , TYPE_11));
}
;
_.addKeyPressHandler = function addKeyPressHandler(handler){
  return $addDomHandler(this, handler, ($clinit_KeyPressEvent() , $clinit_KeyPressEvent() , TYPE_12));
}
;
_.addKeyUpHandler = function addKeyUpHandler(handler){
  return $addDomHandler(this, handler, ($clinit_KeyUpEvent() , $clinit_KeyUpEvent() , TYPE_13));
}
;
function $removeAutoHidePartner(this$static, partner){
  !!this$static.autoHidePartners && $remove_5(this$static.autoHidePartners, partner);
}

function $clearItems(this$static){
  var container, item, item$iterator;
  $selectItem(this$static, null);
  container = this$static.vertical?this$static.body_0:getChild(this$static.body_0, 0);
  while (($clinit_DOM() , impl_7.getChildCount(container)) > 0) {
    $removeChild(container, impl_7.getChild(container, 0));
  }
  for (item$iterator = this$static.allItems.iterator_0(); item$iterator.hasNext_0();) {
    item = dynamicCast(item$iterator.next_0(), Q$UIObject);
    item.element_0['colSpan'] = 1;
    dynamicCast(item, Q$MenuItem).parentMenu = null;
  }
  $clear_3(this$static.items);
  $clear_3(this$static.allItems);
}

function $setCommand(this$static, cmd){
  this$static.command = cmd;
}

function SuggestOracle(){
}

_ = SuggestOracle.prototype = new Object_0;
_.getClass$ = function getClass_520(){
  return Lcom_google_gwt_user_client_ui_SuggestOracle_2_classLit;
}
;
function $convertToFormattedSuggestions(this$static, query, candidates){
  var accum, candidate, cursor, formattedSuggestion, i_0, index, part1, part2, searchWords, suggestion, suggestions, wordBounds;
  suggestions = new ArrayList_0;
  for (i_0 = 0; i_0 < candidates.size_1(); ++i_0) {
    candidate = dynamicCast(candidates.get(i_0), Q$String);
    cursor = 0;
    index = 0;
    formattedSuggestion = dynamicCast(this$static.toRealSuggestions.get_0(candidate), Q$String);
    accum = new SafeHtmlBuilder_0;
    searchWords = $split_0(query, ' ', 0);
    while (true) {
      wordBounds = $findNextWord(candidate, searchWords, index);
      if (!wordBounds) {
        break;
      }
      if (wordBounds.startIndex == 0 || 32 == $charAt(candidate, wordBounds.startIndex - 1)) {
        part1 = $substring_0(formattedSuggestion, cursor, wordBounds.startIndex);
        part2 = $substring_0(formattedSuggestion, wordBounds.startIndex, wordBounds.endIndex);
        cursor = wordBounds.endIndex;
        $append_10(accum.sb, htmlEscape(part1));
        $append_10(accum.sb, '<strong>');
        $append_10(accum.sb, htmlEscape(part2));
        $append_10(accum.sb, '<\/strong>');
      }
      index = wordBounds.endIndex;
    }
    if (cursor == 0) {
      continue;
    }
    $appendEscaped(accum, $substring(formattedSuggestion, cursor));
    suggestion = new MultiWordSuggestOracle$MultiWordSuggestion_0(formattedSuggestion, (new SafeHtmlString_0($toString_8(accum.sb))).html);
    setCheck(suggestions.array, suggestions.size_0++, suggestion);
  }
  return suggestions;
}

function $createCandidatesFromSearch(this$static, query){
  var candidateSet, candidates, i_0, searchWords, thisWordChoices, word;
  candidates = new ArrayList_0;
  if (query.length == 0) {
    return candidates;
  }
  searchWords = $split_0(query, ' ', 0);
  candidateSet = null;
  for (i_0 = 0; i_0 < searchWords.length; ++i_0) {
    word = searchWords[i_0];
    if (word.length == 0 || $matches(word, ' ')) {
      continue;
    }
    thisWordChoices = $createCandidatesFromWord(this$static, word);
    if (!candidateSet) {
      candidateSet = thisWordChoices;
    }
     else {
      $retainAll(candidateSet, thisWordChoices);
      if (candidateSet.map.size_1() < 2) {
        break;
      }
    }
  }
  if (candidateSet) {
    $addAll_0(candidates, candidateSet);
    sort(candidates);
  }
  return candidates;
}

function $createCandidatesFromWord(this$static, query){
  var belongsTo, candidateSet, i_0, words;
  candidateSet = new HashSet_0;
  words = $getSuggestions(this$static.tree, query, 2147483647);
  if (words) {
    for (i_0 = 0; i_0 < words.size_0; ++i_0) {
      belongsTo = dynamicCast(this$static.toCandidates.get_0(words.get(i_0)), Q$Collection);
      !!belongsTo && $addAll(candidateSet, belongsTo);
    }
  }
  return candidateSet;
}

function $findNextWord(candidate, searchWords, indexToStartAt){
  var firstWord, index, newWord, word, word$index, word$max;
  firstWord = null;
  for (word$index = 0 , word$max = searchWords.length; word$index < word$max; ++word$index) {
    word = searchWords[word$index];
    index = candidate.indexOf(word, indexToStartAt);
    if (index != -1) {
      newWord = new MultiWordSuggestOracle$WordBounds_0(index, word.length);
      (!firstWord || $compareTo_0(newWord, firstWord) < 0) && (firstWord = newWord);
    }
  }
  return firstWord;
}

function $normalizeSearch(this$static, search){
  search = $normalizeSuggestion(this$static, search);
  search = $replaceAll(search, '\\s+', ' ');
  return $trim(search);
}

function $normalizeSuggestion(this$static, formattedSuggestion){
  var i_0, ignore;
  formattedSuggestion = formattedSuggestion.toLowerCase();
  if (this$static.whitespaceChars != null) {
    for (i_0 = 0; i_0 < this$static.whitespaceChars.length; ++i_0) {
      ignore = this$static.whitespaceChars[i_0];
      formattedSuggestion = $replace_0(formattedSuggestion, ignore, 32);
    }
  }
  return formattedSuggestion;
}

function $requestDefaultSuggestions(this$static, request, callback){
  $onSuggestionsReady(callback, this$static.emptyResponse);
}

function $requestSuggestions(this$static, request, callback){
  var candidates, i_0, limit, query, response, suggestions;
  query = $normalizeSearch(this$static, request.query);
  limit = request.limit;
  candidates = $createCandidatesFromSearch(this$static, query);
  max_2(0, candidates.size_0 - limit);
  for (i_0 = candidates.size_0 - 1; i_0 > limit; --i_0) {
    $remove_4(candidates, i_0);
  }
  suggestions = $convertToFormattedSuggestions(this$static, query, candidates);
  response = new SuggestOracle$Response_0(suggestions);
  $showSuggestions(callback.this$0.display_0, callback.this$0, response.suggestions, true, true, callback.this$0.suggestionCallback);
}

function MultiWordSuggestOracle_0(){
  MultiWordSuggestOracle_1.call(this);
}

function MultiWordSuggestOracle_1(){
  var i_0;
  this.emptyResponse = new SuggestOracle$Response_0(new ArrayList_0);
  this.tree = new PrefixTree_0;
  this.toCandidates = new HashMap_0;
  this.toRealSuggestions = new HashMap_0;
  this.whitespaceChars = initDim(_3C_classLit, makeCastMap([Q$Serializable, Q$Cloneable]), -1, 1, 1);
  for (i_0 = 0; i_0 < 1; ++i_0) {
    this.whitespaceChars[i_0] = ' '.charCodeAt(i_0);
  }
}

function MultiWordSuggestOracle(){
}

_ = MultiWordSuggestOracle_0.prototype = MultiWordSuggestOracle.prototype = new SuggestOracle;
_.getClass$ = function getClass_521(){
  return Lcom_google_gwt_user_client_ui_MultiWordSuggestOracle_2_classLit;
}
;
_.whitespaceChars = null;
function MultiWordSuggestOracle$MultiWordSuggestion_0(replacementString, displayString){
  this.replacementString = replacementString;
  this.displayString = displayString;
}

function MultiWordSuggestOracle$MultiWordSuggestion(){
}

_ = MultiWordSuggestOracle$MultiWordSuggestion_0.prototype = MultiWordSuggestOracle$MultiWordSuggestion.prototype = new Object_0;
_.getClass$ = function getClass_522(){
  return Lcom_google_gwt_user_client_ui_MultiWordSuggestOracle$MultiWordSuggestion_2_classLit;
}
;
_.castableTypeMap$ = makeCastMap([Q$IsSerializable, Q$SuggestOracle$Suggestion]);
_.displayString = null;
_.replacementString = null;
function $compareTo_0(this$static, that){
  var comparison;
  comparison = this$static.startIndex - that.startIndex;
  comparison == 0 && (comparison = that.endIndex - this$static.endIndex);
  return comparison;
}

function MultiWordSuggestOracle$WordBounds_0(startIndex, length_0){
  this.startIndex = startIndex;
  this.endIndex = startIndex + length_0;
}

function MultiWordSuggestOracle$WordBounds(){
}

_ = MultiWordSuggestOracle$WordBounds_0.prototype = MultiWordSuggestOracle$WordBounds.prototype = new Object_0;
_.compareTo$ = function compareTo_2(that){
  return $compareTo_0(this, dynamicCast(that, Q$MultiWordSuggestOracle$WordBounds));
}
;
_.getClass$ = function getClass_523(){
  return Lcom_google_gwt_user_client_ui_MultiWordSuggestOracle$WordBounds_2_classLit;
}
;
_.castableTypeMap$ = makeCastMap([Q$MultiWordSuggestOracle$WordBounds, Q$Comparable]);
_.endIndex = 0;
_.startIndex = 0;
function $add_13(this$static, s){
  var suffixes = this$static.suffixes;
  var subtrees = this$static.subtrees_0;
  var prefixLength = this$static.prefixLength;
  if (s == null || s.length == 0) {
    return false;
  }
  if (s.length <= prefixLength) {
    var safeKey = ':' + s;
    if (suffixes.hasOwnProperty(safeKey)) {
      return false;
    }
     else {
      this$static.size_0++;
      suffixes[safeKey] = true;
      return true;
    }
  }
   else {
    var prefix = ':' + s.slice(0, prefixLength);
    var theTree;
    if (subtrees.hasOwnProperty(prefix)) {
      theTree = subtrees[prefix];
    }
     else {
      theTree = new PrefixTree_1(prefixLength << 1);
      subtrees[prefix] = theTree;
    }
    var slice = s.slice(prefixLength);
    if (theTree.add_3(slice)) {
      this$static.size_0++;
      return true;
    }
     else {
      return false;
    }
  }
}

function $contains(this$static, s){
  return $indexOf_0($getSuggestions(this$static, s, 1), s, 0) != -1;
}

function $getSuggestions(this$static, search, limit){
  var toReturn;
  toReturn = new ArrayList_0;
  search != null && limit > 0 && $suggestImpl(this$static, search, '', toReturn, limit);
  return toReturn;
}

function $suggestImpl(this$static, search, prefix, output, limit){
  var suffixes = this$static.suffixes;
  var subtrees = this$static.subtrees_0;
  var prefixLength = this$static.prefixLength;
  if (search.length > prefix.length + prefixLength) {
    var key = ':' + search.slice(prefix.length, prefix.length + prefixLength);
    if (subtrees.hasOwnProperty(key)) {
      var subtree = subtrees[key];
      var target = prefix + $substring(key, 1);
      subtree.suggestImpl(search, target, output, limit);
    }
  }
   else {
    for (var suffix in suffixes) {
      if (suffix.indexOf(':') != 0) {
        continue;
      }
      var target = prefix + $substring(suffix, 1);
      target.indexOf(search) == 0 && output.add_0(target);
      if (output.size_1() >= limit) {
        return;
      }
    }
    for (var key in subtrees) {
      if (key.indexOf(':') != 0) {
        continue;
      }
      var target = prefix + $substring(key, 1);
      var subtree = subtrees[key];
      if (target.indexOf(search) == 0) {
        if (subtree.size_0 <= limit - output.size_1() || subtree.size_0 == 1) {
          subtree.dump_0(output, target);
        }
         else {
          for (var suffix in subtree.suffixes) {
            suffix.indexOf(':') == 0 && output.add_0(target + $substring(suffix, 1));
          }
          for (var subkey in subtree.subtrees_0) {
            subkey.indexOf(':') == 0 && output.add_0(target + $substring(subkey, 1) + '...');
          }
        }
      }
    }
  }
}

function PrefixTree_0(){
  PrefixTree_2.call(this, 2);
}

function PrefixTree_1(prefixLength){
  PrefixTree_2.call(this, prefixLength);
}

function PrefixTree_2(prefixLength){
  this.prefixLength = prefixLength;
  this.size_0 = 0;
  this.subtrees_0 = {};
  this.suffixes = {};
}

function safe_0(s){
  return ':' + s;
}

function unsafe_0(s){
  return $substring(s, 1);
}

function PrefixTree(){
}

_ = PrefixTree_1.prototype = PrefixTree_0.prototype = PrefixTree.prototype = new AbstractCollection;
_.add_3 = function add_19(s){
  return $add_13(this, s);
}
;
_.add_0 = function add_20(s){
  return $add_13(this, dynamicCast(s, Q$String));
}
;
_.contains_0 = function contains_2(o){
  return instanceOf(o, Q$String) && $contains(this, dynamicCast(o, Q$String));
}
;
_.dump_0 = function dump_0(output, prefix){
  var s, s$iterator;
  for (s$iterator = new PrefixTree$PrefixTreeIterator_0(this); s$iterator.hasNext_0();) {
    s = s$iterator.next_0();
    output.add_0(prefix + s);
  }
}
;
_.getClass$ = function getClass_548(){
  return Lcom_google_gwt_user_client_ui_PrefixTree_2_classLit;
}
;
_.iterator_0 = function iterator_10(){
  return new PrefixTree$PrefixTreeIterator_0(this);
}
;
_.size_1 = function size_2(){
  return this.size_0;
}
;
_.suggestImpl = function suggestImpl(search, prefix, output, limit){
  $suggestImpl(this, search, prefix, output, limit);
}
;
_.castableTypeMap$ = makeCastMap([Q$Iterable, Q$Collection]);
_.prefixLength = 0;
_.size_0 = 0;
_.subtrees_0 = null;
_.suffixes = null;
function $addTree(this$static, tree, prefix){
  var suffixes = [];
  for (var suffix in tree.suffixes) {
    suffix.indexOf(':') == 0 && suffixes.push(suffix);
  }
  var frame = {suffixNames:suffixes, subtrees:tree.subtrees_0, prefix:prefix, index:0};
  var stack = this$static.stack_0;
  stack.push(frame);
}

function $next_2(this$static){
  var toReturn;
  toReturn = $nextImpl(this$static, false);
  if (toReturn == null) {
    if ($nextImpl(this$static, true) != null) {
      throw new RuntimeException_1('nextImpl() returned null, but hasNext says otherwise');
    }
     else {
      throw new NoSuchElementException_1;
    }
  }
  return toReturn;
}

function $nextImpl(this$static, peek){
  var stack = this$static.stack_0;
  var safe = safe_0;
  var unsafe = unsafe_0;
  while (stack.length > 0) {
    var frame = stack.pop();
    if (frame.index < frame.suffixNames.length) {
      var toReturn = frame.prefix + unsafe(frame.suffixNames[frame.index]);
      !peek && frame.index++;
      if (frame.index < frame.suffixNames.length) {
        stack.push(frame);
      }
       else {
        for (key in frame.subtrees) {
          if (key.indexOf(':') != 0) {
            continue;
          }
          var target = frame.prefix + unsafe(key);
          var subtree = frame.subtrees[key];
          this$static.addTree(subtree, target);
        }
      }
      return toReturn;
    }
     else {
      for (var key in frame.subtrees) {
        if (key.indexOf(':') != 0) {
          continue;
        }
        var target = frame.prefix + unsafe(key);
        var subtree = frame.subtrees[key];
        this$static.addTree(subtree, target);
      }
    }
  }
  return null;
}

function PrefixTree$PrefixTreeIterator_0(tree){
  this.stack_0 = [];
  $addTree(this, tree, '');
}

function PrefixTree$PrefixTreeIterator(){
}

_ = PrefixTree$PrefixTreeIterator_0.prototype = PrefixTree$PrefixTreeIterator.prototype = new Object_0;
_.addTree = function addTree(tree, prefix){
  $addTree(this, tree, prefix);
}
;
_.getClass$ = function getClass_549(){
  return Lcom_google_gwt_user_client_ui_PrefixTree$PrefixTreeIterator_2_classLit;
}
;
_.hasNext_0 = function hasNext_2(){
  return $nextImpl(this, true) != null;
}
;
_.next_0 = function next_3(){
  return $next_2(this);
}
;
_.remove_1 = function remove_21(){
  throw new UnsupportedOperationException_1('PrefixTree does not support removal.  Use clear()');
}
;
_.stack_0 = null;
function $refreshSuggestions(this$static){
  var text;
  text = ($clinit_DOM() , $getPropertyString(this$static.box.element_0, 'value'));
  if ($equals_4(text, this$static.currentText)) {
    return;
  }
   else {
    this$static.currentText = text;
  }
  text.length == 0?$requestDefaultSuggestions(this$static.oracle, new SuggestOracle$Request_0(null), this$static.callback):$requestSuggestions(this$static.oracle, new SuggestOracle$Request_0(text), this$static.callback);
}

function $setNewSelection(this$static, curSuggestion){
  this$static.currentText = curSuggestion.replacementString;
  $setText_6(this$static, this$static.currentText);
  this$static.display_0.suggestionPopup.hide();
  fire_5(this$static, curSuggestion);
}

function $setText_6(this$static, text){
  $setText_4(this$static.box, text);
}

function SuggestBox_0(oracle){
  $clinit_UIObject();
  SuggestBox_1.call(this, oracle, new TextBox_0);
}

function SuggestBox_1(oracle, box){
  SuggestBox_2.call(this, oracle, box, new SuggestBox$DefaultSuggestionDisplay_0);
}

function SuggestBox_2(oracle, box, suggestDisplay){
  var events;
  this.callback = new SuggestBox$1_0(this);
  this.suggestionCallback = new SuggestBox$2_0(this);
  this.box = box;
  this.display_0 = suggestDisplay;
  $initWidget(this, box);
  events = new SuggestBox$1TextBoxEvents_0(this);
  $addKeyHandlersTo(events, this.box);
  $addValueChangeHandler_1(this.box, events);
  this.oracle = oracle;
  setStyleName(this.getStyleElement(), 'gwt-SuggestBox');
}

function SuggestBox(){
}

_ = SuggestBox_0.prototype = SuggestBox.prototype = new Composite;
_.getClass$ = function getClass_573(){
  return Lcom_google_gwt_user_client_ui_SuggestBox_2_classLit;
}
;
_.onEnsureDebugId = function onEnsureDebugId_8(baseID){
  ensureDebugId(this.element_0, '', baseID);
  $onEnsureDebugId(this.display_0, baseID);
}
;
_.setFocus = function setFocus_5(focused){
  $setFocus(this.box, focused);
}
;
_.castableTypeMap$ = makeCastMap([Q$IsEditor, Q$HasAllKeyHandlers, Q$HasKeyDownHandlers, Q$HasKeyPressHandlers, Q$HasKeyUpHandlers, Q$HasAttachHandlers, Q$HasValueChangeHandlers, Q$HasHandlers, Q$EventListener, Q$TakesValue, Q$Focusable, Q$HasFocus, Q$HasText, Q$HasValue, Q$HasVisibility, Q$IsRenderable, Q$IsWidget, Q$SourcesChangeEvents, Q$SourcesClickEvents, Q$SourcesFocusEvents, Q$SourcesKeyboardEvents, Q$UIObject, Q$Widget]);
_.box = null;
_.currentText = null;
_.display_0 = null;
_.oracle = null;
function $onSuggestionsReady(this$static, response){
  $showSuggestions(this$static.this$0.display_0, this$static.this$0, response.suggestions, true, true, this$static.this$0.suggestionCallback);
}

function SuggestBox$1_0(this$0){
  this.this$0 = this$0;
}

function SuggestBox$1(){
}

_ = SuggestBox$1_0.prototype = SuggestBox$1.prototype = new Object_0;
_.getClass$ = function getClass_574(){
  return Lcom_google_gwt_user_client_ui_SuggestBox$1_2_classLit;
}
;
_.this$0 = null;
function SuggestBox$1TextBoxEvents_0(this$0){
  this.this$0 = this$0;
}

function SuggestBox$1TextBoxEvents(){
}

_ = SuggestBox$1TextBoxEvents_0.prototype = SuggestBox$1TextBoxEvents.prototype = new HandlesAllKeyEvents;
_.getClass$ = function getClass_575(){
  return Lcom_google_gwt_user_client_ui_SuggestBox$1TextBoxEvents_2_classLit;
}
;
_.onKeyDown = function onKeyDown(event_0){
  var suggestion;
  switch ($getKeyCode(event_0.nativeEvent)) {
    case 40:
      $moveSelectionDown_0(this.this$0.display_0);
      break;
    case 38:
      $moveSelectionUp_0(this.this$0.display_0);
      break;
    case 13:
    case 9:
      suggestion = $getCurrentSelection(this.this$0.display_0);
      !suggestion?this.this$0.display_0.suggestionPopup.hide():$setNewSelection(this.this$0, suggestion);
  }
  $delegateEvent(this.this$0, event_0);
}
;
_.onKeyPress = function onKeyPress(event_0){
  $delegateEvent(this.this$0, event_0);
}
;
_.onKeyUp = function onKeyUp_0(event_0){
  $refreshSuggestions(this.this$0);
  $delegateEvent(this.this$0, event_0);
}
;
_.onValueChange = function onValueChange_0(event_0){
  $delegateEvent(this.this$0, event_0);
}
;
_.castableTypeMap$ = makeCastMap([Q$KeyDownHandler, Q$KeyPressHandler, Q$KeyUpHandler, Q$ValueChangeHandler, Q$EventHandler]);
_.this$0 = null;
function $onSuggestionSelected(this$static, suggestion){
  $setNewSelection(this$static.this$0, suggestion);
}

function SuggestBox$2_0(this$0){
  this.this$0 = this$0;
}

function SuggestBox$2(){
}

_ = SuggestBox$2_0.prototype = SuggestBox$2.prototype = new Object_0;
_.getClass$ = function getClass_576(){
  return Lcom_google_gwt_user_client_ui_SuggestBox$2_2_classLit;
}
;
_.this$0 = null;
function SuggestBox$SuggestionDisplay(){
}

_ = SuggestBox$SuggestionDisplay.prototype = new Object_0;
_.getClass$ = function getClass_577(){
  return Lcom_google_gwt_user_client_ui_SuggestBox$SuggestionDisplay_2_classLit;
}
;
function $getCurrentSelection(this$static){
  var item;
  if (!this$static.suggestionPopup.showing) {
    return null;
  }
  item = this$static.suggestionMenu.selectedItem;
  return !item?null:dynamicCast(item, Q$SuggestBox$SuggestionMenuItem).suggestion;
}

function $moveSelectionDown_0(this$static){
  this$static.suggestionPopup.showing && $selectItem_0(this$static.suggestionMenu, $getSelectedItemIndex(this$static.suggestionMenu) + 1);
}

function $moveSelectionUp_0(this$static){
  this$static.suggestionPopup.showing && ($getSelectedItemIndex(this$static.suggestionMenu) == -1?$selectItem_0(this$static.suggestionMenu, this$static.suggestionMenu.items.size_0 - 1):$selectItem_0(this$static.suggestionMenu, $getSelectedItemIndex(this$static.suggestionMenu) - 1));
}

function $onEnsureDebugId(this$static, baseID){
  $ensureDebugId(this$static.suggestionPopup, baseID + '-popup');
  $setMenuItemDebugIds(this$static.suggestionMenu, baseID);
}

function $showSuggestions(this$static, suggestBox, suggestions, isDisplayStringHTML, isAutoSelectEnabled, callback){
  var anySuggestions, curSuggestion, curSuggestion$iterator, menuItem;
  anySuggestions = !!suggestions && suggestions.size_1() > 0;
  if (!anySuggestions) {
    this$static.suggestionPopup.hide();
    return;
  }
  this$static.suggestionPopup.attached && this$static.suggestionPopup.hide();
  $clearItems(this$static.suggestionMenu);
  for (curSuggestion$iterator = suggestions.iterator_0(); curSuggestion$iterator.hasNext_0();) {
    curSuggestion = dynamicCast(curSuggestion$iterator.next_0(), Q$SuggestOracle$Suggestion);
    menuItem = new SuggestBox$SuggestionMenuItem_0(curSuggestion, isDisplayStringHTML);
    $setCommand(menuItem, new SuggestBox$DefaultSuggestionDisplay$1_0(callback, curSuggestion));
    $addItem_0(this$static.suggestionMenu, menuItem);
  }
  isAutoSelectEnabled && anySuggestions && $selectItem_0(this$static.suggestionMenu, 0);
  if (this$static.lastSuggestBox != suggestBox) {
    !!this$static.lastSuggestBox && $removeAutoHidePartner(this$static.suggestionPopup, this$static.lastSuggestBox.element_0);
    this$static.lastSuggestBox = suggestBox;
    $addAutoHidePartner(this$static.suggestionPopup, suggestBox.element_0);
  }
  $showRelativeTo(this$static.suggestionPopup, suggestBox);
}

function SuggestBox$DefaultSuggestionDisplay_0(){
  var p;
  this.suggestionMenu = new SuggestBox$SuggestionMenu_0;
  this.suggestionPopup = (p = new DecoratedPopupPanel_0(true, false, 'suggestPopup') , setStyleName(p.getStyleElement(), 'gwt-SuggestBoxPopup') , p.previewAllNativeEvents = true , p.animType = 2 , p);
  $setWidget_2(this.suggestionPopup, this.suggestionMenu);
}

function SuggestBox$DefaultSuggestionDisplay(){
}

_ = SuggestBox$DefaultSuggestionDisplay_0.prototype = SuggestBox$DefaultSuggestionDisplay.prototype = new SuggestBox$SuggestionDisplay;
_.getClass$ = function getClass_578(){
  return Lcom_google_gwt_user_client_ui_SuggestBox$DefaultSuggestionDisplay_2_classLit;
}
;
_.lastSuggestBox = null;
_.suggestionMenu = null;
_.suggestionPopup = null;
function SuggestBox$DefaultSuggestionDisplay$1_0(val$callback, val$curSuggestion){
  this.val$callback = val$callback;
  this.val$curSuggestion = val$curSuggestion;
}

function SuggestBox$DefaultSuggestionDisplay$1(){
}

_ = SuggestBox$DefaultSuggestionDisplay$1_0.prototype = SuggestBox$DefaultSuggestionDisplay$1.prototype = new Object_0;
_.execute_1 = function execute_25(){
  $onSuggestionSelected(this.val$callback, this.val$curSuggestion);
}
;
_.getClass$ = function getClass_579(){
  return Lcom_google_gwt_user_client_ui_SuggestBox$DefaultSuggestionDisplay$1_2_classLit;
}
;
_.castableTypeMap$ = makeCastMap([Q$Command]);
_.val$callback = null;
_.val$curSuggestion = null;
function $getSelectedItemIndex(this$static){
  var selectedItem;
  selectedItem = this$static.selectedItem;
  if (selectedItem) {
    return $indexOf_0(this$static.items, selectedItem, 0);
  }
  return -1;
}

function $selectItem_0(this$static, index){
  var items;
  items = this$static.items;
  index > -1 && index < items.size_0 && $itemOver(this$static, dynamicCast(items.get(index), Q$MenuItem), false);
}

function SuggestBox$SuggestionMenu_0(){
  $clinit_UIObject();
  MenuBar_1.call(this, true);
  setStyleName(this.getStyleElement(), '');
  this.focusOnHover = false;
}

function SuggestBox$SuggestionMenu(){
}

_ = SuggestBox$SuggestionMenu_0.prototype = SuggestBox$SuggestionMenu.prototype = new MenuBar;
_.getClass$ = function getClass_580(){
  return Lcom_google_gwt_user_client_ui_SuggestBox$SuggestionMenu_2_classLit;
}
;
_.castableTypeMap$ = makeCastMap([Q$HasAttachHandlers, Q$HasHandlers, Q$EventListener, Q$HasVisibility, Q$IsWidget, Q$PopupListener, Q$UIObject, Q$Widget]);
function SuggestBox$SuggestionMenuItem_0(suggestion, asHTML){
  $clinit_UIObject();
  MenuItem_2.call(this, suggestion.displayString, asHTML);
  setStyleAttribute(this.element_0, 'whiteSpace', 'nowrap');
  setStyleName(this.getStyleElement(), 'item');
  this.suggestion = suggestion;
}

function SuggestBox$SuggestionMenuItem(){
}

_ = SuggestBox$SuggestionMenuItem_0.prototype = SuggestBox$SuggestionMenuItem.prototype = new MenuItem;
_.getClass$ = function getClass_581(){
  return Lcom_google_gwt_user_client_ui_SuggestBox$SuggestionMenuItem_2_classLit;
}
;
_.castableTypeMap$ = makeCastMap([Q$HasSafeHtml, Q$HasEnabled, Q$HasHTML, Q$HasText, Q$HasVisibility, Q$MenuItem, Q$SuggestBox$SuggestionMenuItem, Q$UIObject]);
_.suggestion = null;
function SuggestOracle$Request_0(query){
  this.query = query;
  this.limit = 20;
}

function SuggestOracle$Request(){
}

_ = SuggestOracle$Request_0.prototype = SuggestOracle$Request.prototype = new Object_0;
_.getClass$ = function getClass_582(){
  return Lcom_google_gwt_user_client_ui_SuggestOracle$Request_2_classLit;
}
;
_.castableTypeMap$ = makeCastMap([Q$IsSerializable]);
_.limit = 20;
_.query = null;
function SuggestOracle$Response_0(suggestions){
  this.suggestions = suggestions;
}

function SuggestOracle$Response(){
}

_ = SuggestOracle$Response_0.prototype = SuggestOracle$Response.prototype = new Object_0;
_.getClass$ = function getClass_583(){
  return Lcom_google_gwt_user_client_ui_SuggestOracle$Response_2_classLit;
}
;
_.castableTypeMap$ = makeCastMap([Q$IsSerializable]);
_.suggestions = null;
function BasicClosableToolAbstract(){
}

_ = BasicClosableToolAbstract.prototype = new Object_0;
_.getClass$ = function getClass_700(){
  return Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_BasicClosableToolAbstract_2_classLit;
}
;
_.closeButton_ = null;
_.contentPanel_ = null;
_.dialogBox_ = null;
function BasicClosableToolAbstract$1_0(this$0){
  this.this$0 = this$0;
}

function BasicClosableToolAbstract$1(){
}

_ = BasicClosableToolAbstract$1_0.prototype = BasicClosableToolAbstract$1.prototype = new Object_0;
_.getClass$ = function getClass_701(){
  return Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_BasicClosableToolAbstract$1_2_classLit;
}
;
_.onClick = function onClick_11(event_0){
  this.this$0.dialogBox_.hide();
}
;
_.castableTypeMap$ = makeCastMap([Q$ClickHandler, Q$EventHandler]);
_.this$0 = null;
function $clinit_EquipmentCacheTool(){
  $clinit_EquipmentCacheTool = nullMethod;
  $clinit_ClientLogger();
}

function EquipmentCacheTool_0(){
  $clinit_EquipmentCacheTool();
  this.dialogBox_ = new DialogBox_1;
  this.dialogBox_.modal = false;
  $setGlassEnabled(this.dialogBox_, false);
  $setText_2(this.dialogBox_, 'Equipment cache');
  $setStyleName_0(this.dialogBox_, 'mwt-debugTools');
  this.contentPanel_ = new VerticalPanel_0;
  $setWidget_2(this.dialogBox_, this.contentPanel_);
  $add_16(this.contentPanel_, (this.oracle_ = new MultiWordSuggestOracle_0 , this.suggestBox_ = new SuggestBox_0(this.oracle_) , this.showCacheButton_ = new Button_1('Show cache') , this.logCacheButton_ = new Button_1('Log cache') , this.clickHandler_ = new EquipmentCacheTool$1_0(this) , $addDomHandler(this.showCacheButton_, this.clickHandler_, ($clinit_ClickEvent() , $clinit_ClickEvent() , TYPE_1)) , $addDomHandler(this.logCacheButton_, this.clickHandler_, TYPE_1) , this.container_ = new HorizontalPanel_0 , $add_11(this.container_, this.suggestBox_) , $add_11(this.container_, this.showCacheButton_) , $add_11(this.container_, this.logCacheButton_) , this.container_));
  this.closeButton_ = new Button_1('Close');
  $addDomHandler(this.closeButton_, new BasicClosableToolAbstract$1_0(this), TYPE_1);
  $add_16(this.contentPanel_, this.closeButton_);
}

function EquipmentCacheTool(){
}

_ = EquipmentCacheTool_0.prototype = EquipmentCacheTool.prototype = new BasicClosableToolAbstract;
_.getClass$ = function getClass_702(){
  return Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_EquipmentCacheTool_2_classLit;
}
;
_.clickHandler_ = null;
_.container_ = null;
_.logCacheButton_ = null;
_.oracle_ = null;
_.showCacheButton_ = null;
_.suggestBox_ = null;
function EquipmentCacheTool$1_0(this$0){
  this.this$0 = this$0;
}

function EquipmentCacheTool$1(){
}

_ = EquipmentCacheTool$1_0.prototype = EquipmentCacheTool$1.prototype = new Object_0;
_.getClass$ = function getClass_703(){
  return Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_EquipmentCacheTool$1_2_classLit;
}
;
_.onClick = function onClick_12(event_0){
  var currentEqpt;
  currentEqpt = $getValue_2(this.this$0.suggestBox_.box);
  currentEqpt != null && !$equals_4('', currentEqpt) && (maskUndefined(event_0.source) === maskUndefined(this.this$0.showCacheButton_)?alert_0('getEquipmentCache(final String ' + currentEqpt + ') to be updated in VS9'):maskUndefined(event_0.source) === maskUndefined(this.this$0.logCacheButton_) && $debug(($clinit_EquipmentCacheTool() , 'Equipment cache: \ngetEquipmentCache(final String ' + currentEqpt + ') to be updated in VS9')));
}
;
_.castableTypeMap$ = makeCastMap([Q$ClickHandler, Q$EventHandler]);
_.this$0 = null;
function $addItem_3(this$static, item){
  var btn;
  btn = new Button_1('Equipment cache');
  $clinit_DOM();
  btn.element_0.setAttribute('title', 'Show an equipment cache overview');
  $addDomHandler(btn, new MwtDebugTools$1_0(item), ($clinit_ClickEvent() , $clinit_ClickEvent() , TYPE_1));
  $add_16(this$static.contentPanel_, btn);
}

function MwtDebugTools_0(){
  $clinit_MwtDebugTools();
  this.contentPanel_ = new VerticalPanel_0;
  this.dialogBox_ = new DialogBox_1;
  this.dialogBox_.modal = false;
  $setGlassEnabled(this.dialogBox_, false);
  $setText_2(this.dialogBox_, 'MWT Debug Tools');
  $setWidget_2(this.dialogBox_, this.contentPanel_);
  $setStyleName_0(this.dialogBox_, 'mwt-debugTools');
  $addItem_3(this, new EquipmentCacheTool_0);
  this.closeButton_ = new Button_1('Close');
  $addDomHandler(this.closeButton_, new MwtDebugTools$2_0(this), ($clinit_ClickEvent() , $clinit_ClickEvent() , TYPE_1));
  $add_16(this.contentPanel_, this.closeButton_);
  $center(this.dialogBox_);
}

function MwtDebugTools(){
}

_ = MwtDebugTools_0.prototype = MwtDebugTools.prototype = new Object_0;
_.getClass$ = function getClass_704(){
  return Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_MwtDebugTools_2_classLit;
}
;
_.closeButton_ = null;
_.contentPanel_ = null;
_.dialogBox_ = null;
var instance_ = null;
function MwtDebugTools$1_0(val$item){
  this.val$item = val$item;
}

function MwtDebugTools$1(){
}

_ = MwtDebugTools$1_0.prototype = MwtDebugTools$1.prototype = new Object_0;
_.getClass$ = function getClass_705(){
  return Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_MwtDebugTools$1_2_classLit;
}
;
_.onClick = function onClick_13(event_0){
  $center(this.val$item.dialogBox_);
}
;
_.castableTypeMap$ = makeCastMap([Q$ClickHandler, Q$EventHandler]);
_.val$item = null;
function MwtDebugTools$2_0(this$0){
  this.this$0 = this$0;
}

function MwtDebugTools$2(){
}

_ = MwtDebugTools$2_0.prototype = MwtDebugTools$2.prototype = new Object_0;
_.getClass$ = function getClass_706(){
  return Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_MwtDebugTools$2_2_classLit;
}
;
_.onClick = function onClick_14(event_0){
  this.this$0.dialogBox_.hide();
}
;
_.castableTypeMap$ = makeCastMap([Q$ClickHandler, Q$EventHandler]);
_.this$0 = null;
_ = MwtDebugTools$3.prototype;
_.onSuccess = function onSuccess_0(){
  !($clinit_MwtDebugTools() , instance_) && (instance_ = new MwtDebugTools_0);
  $center(instance_.dialogBox_);
}
;
function NoSuchElementException_1(){
  RuntimeException_1.call(this, 'No more elements in the iterator');
}

_ = NoSuchElementException_1.prototype = NoSuchElementException.prototype;
var Lcom_google_gwt_event_dom_client_HandlesAllKeyEvents_2_classLit = createForClass('com.google.gwt.event.dom.client.', 'HandlesAllKeyEvents'), Lcom_google_gwt_user_client_ui_SuggestOracle_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestOracle'), Lcom_google_gwt_user_client_ui_MultiWordSuggestOracle_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'MultiWordSuggestOracle'), Lcom_google_gwt_user_client_ui_MultiWordSuggestOracle$MultiWordSuggestion_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'MultiWordSuggestOracle$MultiWordSuggestion'), Lcom_google_gwt_user_client_ui_MultiWordSuggestOracle$WordBounds_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'MultiWordSuggestOracle$WordBounds'), Lcom_google_gwt_user_client_ui_PrefixTree_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'PrefixTree'), Lcom_google_gwt_user_client_ui_PrefixTree$PrefixTreeIterator_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'PrefixTree$PrefixTreeIterator'), Lcom_google_gwt_user_client_ui_SuggestBox_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestBox'), Lcom_google_gwt_user_client_ui_SuggestBox$1_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestBox$1'), Lcom_google_gwt_user_client_ui_SuggestBox$1TextBoxEvents_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestBox$1TextBoxEvents'), Lcom_google_gwt_user_client_ui_SuggestBox$2_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestBox$2'), Lcom_google_gwt_user_client_ui_SuggestBox$SuggestionDisplay_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestBox$SuggestionDisplay'), Lcom_google_gwt_user_client_ui_SuggestBox$DefaultSuggestionDisplay_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestBox$DefaultSuggestionDisplay'), Lcom_google_gwt_user_client_ui_SuggestBox$DefaultSuggestionDisplay$1_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestBox$DefaultSuggestionDisplay$1'), Lcom_google_gwt_user_client_ui_SuggestBox$SuggestionMenu_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestBox$SuggestionMenu'), Lcom_google_gwt_user_client_ui_SuggestBox$SuggestionMenuItem_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestBox$SuggestionMenuItem'), Lcom_google_gwt_user_client_ui_SuggestOracle$Request_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestOracle$Request'), Lcom_google_gwt_user_client_ui_SuggestOracle$Response_2_classLit = createForClass('com.google.gwt.user.client.ui.', 'SuggestOracle$Response'), Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_BasicClosableToolAbstract_2_classLit = createForClass('com.thalesgroup.hypervisor.mwt.core.webapp.core.common.client.tools.debug.', 'BasicClosableToolAbstract'), Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_BasicClosableToolAbstract$1_2_classLit = createForClass('com.thalesgroup.hypervisor.mwt.core.webapp.core.common.client.tools.debug.', 'BasicClosableToolAbstract$1'), Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_EquipmentCacheTool_2_classLit = createForClass('com.thalesgroup.hypervisor.mwt.core.webapp.core.common.client.tools.debug.', 'EquipmentCacheTool'), Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_EquipmentCacheTool$1_2_classLit = createForClass('com.thalesgroup.hypervisor.mwt.core.webapp.core.common.client.tools.debug.', 'EquipmentCacheTool$1'), Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_MwtDebugTools_2_classLit = createForClass('com.thalesgroup.hypervisor.mwt.core.webapp.core.common.client.tools.debug.', 'MwtDebugTools'), Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_MwtDebugTools$1_2_classLit = createForClass('com.thalesgroup.hypervisor.mwt.core.webapp.core.common.client.tools.debug.', 'MwtDebugTools$1'), Lcom_thalesgroup_hypervisor_mwt_core_webapp_core_common_client_tools_debug_MwtDebugTools$2_2_classLit = createForClass('com.thalesgroup.hypervisor.mwt.core.webapp.core.common.client.tools.debug.', 'MwtDebugTools$2');
$entry(onLoad)(1);
