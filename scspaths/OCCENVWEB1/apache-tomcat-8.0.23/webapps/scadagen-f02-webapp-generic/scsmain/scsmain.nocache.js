function scsmain(){
  var $wnd_0 = window, $doc_0 = document, $stats = $wnd_0.__gwtStatsEvent?function(a){
    return $wnd_0.__gwtStatsEvent(a);
  }
  :null, $sessionId_0 = $wnd_0.__gwtStatsSessionId?$wnd_0.__gwtStatsSessionId:null, scriptsDone, loadDone, bodyDone, base = '', metaProps = {}, values = [], providers = [], answers = [], softPermutationId = 0, onLoadErrorFunc, propertyErrorFunc;
  $stats && $stats({moduleName:'scsmain', sessionId:$sessionId_0, subSystem:'startup', evtGroup:'bootstrap', millis:(new Date).getTime(), type:'begin'});
  if (!$wnd_0.__gwt_stylesLoaded) {
    $wnd_0.__gwt_stylesLoaded = {};
  }
  if (!$wnd_0.__gwt_scriptsLoaded) {
    $wnd_0.__gwt_scriptsLoaded = {};
  }
  function isHostedMode(){
    var result = false;
    try {
      var query = $wnd_0.location.search;
      return (query.indexOf('gwt.codesvr=') != -1 || (query.indexOf('gwt.hosted=') != -1 || $wnd_0.external && $wnd_0.external.gwtOnLoad)) && query.indexOf('gwt.hybrid') == -1;
    }
     catch (e) {
    }
    isHostedMode = function(){
      return result;
    }
    ;
    return result;
  }

  function maybeStartModule(){
    if (scriptsDone && loadDone) {
      var iframe = $doc_0.getElementById('scsmain');
      var frameWnd = iframe.contentWindow;
      if (isHostedMode()) {
        frameWnd.__gwt_getProperty = function(name_0){
          return computePropValue(name_0);
        }
        ;
      }
      scsmain = null;
      frameWnd.gwtOnLoad(onLoadErrorFunc, 'scsmain', base, softPermutationId);
      $stats && $stats({moduleName:'scsmain', sessionId:$sessionId_0, subSystem:'startup', evtGroup:'moduleStartup', millis:(new Date).getTime(), type:'end'});
    }
  }

  function computeScriptBase(){
    function getDirectoryOfFile(path){
      var hashIndex = path.lastIndexOf('#');
      if (hashIndex == -1) {
        hashIndex = path.length;
      }
      var queryIndex = path.indexOf('?');
      if (queryIndex == -1) {
        queryIndex = path.length;
      }
      var slashIndex = path.lastIndexOf('/', Math.min(queryIndex, hashIndex));
      return slashIndex >= 0?path.substring(0, slashIndex + 1):'';
    }

    function ensureAbsoluteUrl(url){
      if (url.match(/^\w+:\/\//)) {
      }
       else {
        var img = $doc_0.createElement('img');
        img.src = url + 'clear.cache.gif';
        url = getDirectoryOfFile(img.src);
      }
      return url;
    }

    function tryMetaTag(){
      var metaVal = __gwt_getMetaProperty('baseUrl');
      if (metaVal != null) {
        return metaVal;
      }
      return '';
    }

    function tryNocacheJsTag(){
      var scriptTags = $doc_0.getElementsByTagName('script');
      for (var i_0 = 0; i_0 < scriptTags.length; ++i_0) {
        if (scriptTags[i_0].src.indexOf('scsmain.nocache.js') != -1) {
          return getDirectoryOfFile(scriptTags[i_0].src);
        }
      }
      return '';
    }

    function tryMarkerScript(){
      var thisScript;
      if (typeof isBodyLoaded == 'undefined' || !isBodyLoaded()) {
        var markerId = '__gwt_marker_scsmain';
        var markerScript;
        $doc_0.write('<script id="' + markerId + '"><\/script>');
        markerScript = $doc_0.getElementById(markerId);
        thisScript = markerScript && markerScript.previousSibling;
        while (thisScript && thisScript.tagName != 'SCRIPT') {
          thisScript = thisScript.previousSibling;
        }
        if (markerScript) {
          markerScript.parentNode.removeChild(markerScript);
        }
        if (thisScript && thisScript.src) {
          return getDirectoryOfFile(thisScript.src);
        }
      }
      return '';
    }

    function tryBaseTag(){
      var baseElements = $doc_0.getElementsByTagName('base');
      if (baseElements.length > 0) {
        return baseElements[baseElements.length - 1].href;
      }
      return '';
    }

    var tempBase = tryMetaTag();
    if (tempBase == '') {
      tempBase = tryNocacheJsTag();
    }
    if (tempBase == '') {
      tempBase = tryMarkerScript();
    }
    if (tempBase == '') {
      tempBase = tryBaseTag();
    }
    if (tempBase == '') {
      tempBase = getDirectoryOfFile($doc_0.location.href);
    }
    tempBase = ensureAbsoluteUrl(tempBase);
    base = tempBase;
    return tempBase;
  }

  function processMetas(){
    var metas = document.getElementsByTagName('meta');
    for (var i_0 = 0, n = metas.length; i_0 < n; ++i_0) {
      var meta = metas[i_0], name_0 = meta.getAttribute('name'), content_0;
      if (name_0) {
        name_0 = name_0.replace('scsmain::', '');
        if (name_0.indexOf('::') >= 0) {
          continue;
        }
        if (name_0 == 'gwt:property') {
          content_0 = meta.getAttribute('content');
          if (content_0) {
            var value, eq = content_0.indexOf('=');
            if (eq >= 0) {
              name_0 = content_0.substring(0, eq);
              value = content_0.substring(eq + 1);
            }
             else {
              name_0 = content_0;
              value = '';
            }
            metaProps[name_0] = value;
          }
        }
         else if (name_0 == 'gwt:onPropertyErrorFn') {
          content_0 = meta.getAttribute('content');
          if (content_0) {
            try {
              propertyErrorFunc = eval(content_0);
            }
             catch (e) {
              alert('Bad handler "' + content_0 + '" for "gwt:onPropertyErrorFn"');
            }
          }
        }
         else if (name_0 == 'gwt:onLoadErrorFn') {
          content_0 = meta.getAttribute('content');
          if (content_0) {
            try {
              onLoadErrorFunc = eval(content_0);
            }
             catch (e) {
              alert('Bad handler "' + content_0 + '" for "gwt:onLoadErrorFn"');
            }
          }
        }
      }
    }
  }

  function __gwt_isKnownPropertyValue(propName, propValue){
    return propValue in values[propName];
  }

  function __gwt_getMetaProperty(name_0){
    var value = metaProps[name_0];
    return value == null?null:value;
  }

  function unflattenKeylistIntoAnswers(propValArray, value){
    var answer = answers;
    for (var i_0 = 0, n = propValArray.length - 1; i_0 < n; ++i_0) {
      answer = answer[propValArray[i_0]] || (answer[propValArray[i_0]] = []);
    }
    answer[propValArray[n]] = value;
  }

  function computePropValue(propName){
    var value = providers[propName](), allowedValuesMap = values[propName];
    if (value in allowedValuesMap) {
      return value;
    }
    var allowedValuesList = [];
    for (var k in allowedValuesMap) {
      allowedValuesList[allowedValuesMap[k]] = k;
    }
    if (propertyErrorFunc) {
      propertyErrorFunc(propName, allowedValuesList, value);
    }
    throw null;
  }

  var frameInjected;
  function maybeInjectFrame(){
    if (!frameInjected) {
      frameInjected = true;
      var iframe = $doc_0.createElement('iframe');
      iframe.src = "javascript:''";
      iframe.id = 'scsmain';
      iframe.style.cssText = 'position:absolute;width:0;height:0;border:none';
      iframe.tabIndex = -1;
      $doc_0.body.appendChild(iframe);
      $stats && $stats({moduleName:'scsmain', sessionId:$sessionId_0, subSystem:'startup', evtGroup:'moduleStartup', millis:(new Date).getTime(), type:'moduleRequested'});
      iframe.contentWindow.location.replace(base + initialHtml);
    }
  }

  providers['log_level'] = function(){
    var log_level;
    if (log_level == null) {
      var regex = new RegExp('[\\?&]log_level=([^&#]*)');
      var results = regex.exec(location.search);
      if (results != null) {
        log_level = results[1];
      }
    }
    if (log_level == null) {
      log_level = __gwt_getMetaProperty('log_level');
    }
    if (!__gwt_isKnownPropertyValue('log_level', log_level)) {
      var levels = ['TRACE', 'DEBUG', 'INFO', 'WARN', 'ERROR', 'FATAL', 'OFF'];
      var possibleLevel = null;
      var foundRequestedLevel = false;
      for (i in levels) {
        foundRequestedLevel |= log_level == levels[i];
        if (__gwt_isKnownPropertyValue('log_level', levels[i])) {
          possibleLevel = levels[i];
        }
        if (i == levels.length - 1 || foundRequestedLevel && possibleLevel != null) {
          log_level = possibleLevel;
          break;
        }
      }
    }
    return log_level;
  }
  ;
  values['log_level'] = {DEBUG:0, INFO:1, WARN:2};
  providers['user.agent'] = function(){
    var ua = navigator.userAgent.toLowerCase();
    var makeVersion = function(result){
      return parseInt(result[1]) * 1000 + parseInt(result[2]);
    }
    ;
    if (function(){
      return ua.indexOf('opera') != -1;
    }
    ())
      return 'opera';
    if (function(){
      return ua.indexOf('webkit') != -1 || function(){
        if (ua.indexOf('chromeframe') != -1) {
          return true;
        }
        if (typeof window['ActiveXObject'] != 'undefined') {
          try {
            var obj = new ActiveXObject('ChromeTab.ChromeFrame');
            if (obj) {
              obj.registerBhoIfNeeded();
              return true;
            }
          }
           catch (e) {
          }
        }
        return false;
      }
      ();
    }
    ())
      return 'safari';
    if (function(){
      return ua.indexOf('msie') != -1 && $doc_0.documentMode >= 9;
    }
    ())
      return 'ie9';
    if (function(){
      return ua.indexOf('msie') != -1 && $doc_0.documentMode >= 8;
    }
    ())
      return 'ie8';
    if (function(){
      var result = /msie ([0-9]+)\.([0-9]+)/.exec(ua);
      if (result && result.length == 3)
        return makeVersion(result) >= 6000;
    }
    ())
      return 'ie6';
    if (function(){
      return ua.indexOf('gecko') != -1;
    }
    ())
      return 'gecko1_8';
    return 'unknown';
  }
  ;
  values['user.agent'] = {gecko1_8:0, ie6:1, ie8:2, ie9:3, opera:4, safari:5};
  scsmain.onScriptLoad = function(){
    if (frameInjected) {
      loadDone = true;
      maybeStartModule();
    }
  }
  ;
  scsmain.onInjectionDone = function(){
    scriptsDone = true;
    $stats && $stats({moduleName:'scsmain', sessionId:$sessionId_0, subSystem:'startup', evtGroup:'loadExternalRefs', millis:(new Date).getTime(), type:'end'});
    maybeStartModule();
  }
  ;
  processMetas();
  computeScriptBase();
  var strongName;
  var initialHtml;
  if (isHostedMode()) {
    if ($wnd_0.external && ($wnd_0.external.initModule && $wnd_0.external.initModule('scsmain'))) {
      $wnd_0.location.reload();
      return;
    }
    initialHtml = 'hosted.html?scsmain';
    strongName = '';
  }
  $stats && $stats({moduleName:'scsmain', sessionId:$sessionId_0, subSystem:'startup', evtGroup:'bootstrap', millis:(new Date).getTime(), type:'selectingPermutation'});
  if (!isHostedMode()) {
    try {
      unflattenKeylistIntoAnswers(['DEBUG', 'gecko1_8'], '4E1CE15468810B0040A78709AC7DC270');
      unflattenKeylistIntoAnswers(['DEBUG', 'ie9'], '4E1CE15468810B0040A78709AC7DC270' + ':1');
      unflattenKeylistIntoAnswers(['DEBUG', 'safari'], '4E1CE15468810B0040A78709AC7DC270' + ':2');
      unflattenKeylistIntoAnswers(['INFO', 'gecko1_8'], '4E1CE15468810B0040A78709AC7DC270' + ':3');
      unflattenKeylistIntoAnswers(['INFO', 'ie9'], '4E1CE15468810B0040A78709AC7DC270' + ':4');
      unflattenKeylistIntoAnswers(['INFO', 'safari'], '4E1CE15468810B0040A78709AC7DC270' + ':5');
      unflattenKeylistIntoAnswers(['WARN', 'gecko1_8'], '4E1CE15468810B0040A78709AC7DC270' + ':6');
      unflattenKeylistIntoAnswers(['WARN', 'ie9'], '4E1CE15468810B0040A78709AC7DC270' + ':7');
      unflattenKeylistIntoAnswers(['WARN', 'safari'], '4E1CE15468810B0040A78709AC7DC270' + ':8');
      strongName = answers[computePropValue('log_level')][computePropValue('user.agent')];
      var idx = strongName.indexOf(':');
      if (idx != -1) {
        softPermutationId = Number(strongName.substring(idx + 1));
        strongName = strongName.substring(0, idx);
      }
      initialHtml = strongName + '.cache.html';
    }
     catch (e) {
      return;
    }
  }
  var onBodyDoneTimerId;
  function onBodyDone(){
    if (!bodyDone) {
      bodyDone = true;
      if (!__gwt_stylesLoaded['css/scsmwt-scada.css']) {
        var l = $doc_0.createElement('link');
        __gwt_stylesLoaded['css/scsmwt-scada.css'] = l;
        l.setAttribute('rel', 'stylesheet');
        l.setAttribute('href', base + 'css/scsmwt-scada.css');
        $doc_0.getElementsByTagName('head')[0].appendChild(l);
      }
      if (!__gwt_stylesLoaded['gwt/standard/standard.css']) {
        var l = $doc_0.createElement('link');
        __gwt_stylesLoaded['gwt/standard/standard.css'] = l;
        l.setAttribute('rel', 'stylesheet');
        l.setAttribute('href', base + 'gwt/standard/standard.css');
        $doc_0.getElementsByTagName('head')[0].appendChild(l);
      }
      maybeStartModule();
      if ($doc_0.removeEventListener) {
        $doc_0.removeEventListener('DOMContentLoaded', onBodyDone, false);
      }
      if (onBodyDoneTimerId) {
        clearInterval(onBodyDoneTimerId);
      }
    }
  }

  if ($doc_0.addEventListener) {
    $doc_0.addEventListener('DOMContentLoaded', function(){
      maybeInjectFrame();
      onBodyDone();
    }
    , false);
  }
  var onBodyDoneTimerId = setInterval(function(){
    if (/loaded|complete/.test($doc_0.readyState)) {
      maybeInjectFrame();
      onBodyDone();
    }
  }
  , 50);
  $stats && $stats({moduleName:'scsmain', sessionId:$sessionId_0, subSystem:'startup', evtGroup:'bootstrap', millis:(new Date).getTime(), type:'end'});
  $stats && $stats({moduleName:'scsmain', sessionId:$sessionId_0, subSystem:'startup', evtGroup:'loadExternalRefs', millis:(new Date).getTime(), type:'begin'});
  if (!__gwt_scriptsLoaded['js/gwt-openlayers/util.js']) {
    __gwt_scriptsLoaded['js/gwt-openlayers/util.js'] = true;
    document.write('<script language="javascript" src="' + base + 'js/gwt-openlayers/util.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/OpenLayers.js']) {
    __gwt_scriptsLoaded['lib/OpenLayers.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/OpenLayers.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.canvas.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.canvas.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.canvas.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.crosshair.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.crosshair.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.crosshair.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.navigate.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.navigate.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.navigate.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.pie.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.pie.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.pie.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.resize.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.resize.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.resize.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.stack.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.stack.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.stack.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.selection.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.selection.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.selection.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.symbol.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.symbol.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.symbol.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.time.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.time.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.time.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.axislabels.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.axislabels.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.axislabels.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.axisnavigate.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.axisnavigate.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.axisnavigate.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.downsample.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.downsample.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.downsample.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.tickrotor.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.tickrotor.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.tickrotor.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/jquery.flot.tooltip.min.js']) {
    __gwt_scriptsLoaded['lib/flot/jquery.flot.tooltip.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/jquery.flot.tooltip.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/base64.js']) {
    __gwt_scriptsLoaded['lib/flot/base64.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/base64.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/flot/canvas2image.js']) {
    __gwt_scriptsLoaded['lib/flot/canvas2image.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/flot/canvas2image.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/justgage/justgage.js']) {
    __gwt_scriptsLoaded['lib/justgage/justgage.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/justgage/justgage.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/justgage/raphael-2.1.4.min.js']) {
    __gwt_scriptsLoaded['lib/justgage/raphael-2.1.4.min.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/justgage/raphael-2.1.4.min.js"><\/script>');
  }
  if (!__gwt_scriptsLoaded['lib/html2canvas.js']) {
    __gwt_scriptsLoaded['lib/html2canvas.js'] = true;
    document.write('<script language="javascript" src="' + base + 'lib/html2canvas.js"><\/script>');
  }
  $doc_0.write('<script defer="defer">scsmain.onInjectionDone(\'scsmain\')<\/script>');
}

scsmain();
