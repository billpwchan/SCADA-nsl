// --------------------------------------------------------------------------
// Pnl Studio commands
// --------------------------------------------------------------------------


command SCADACommand {
  label "&scadapanel";
  prompt "&scadapanel";
  tooltip "&scadapanel";
  bitmap "icons/scada.png";
  category scadasoft;
}

command FgdColor {
  label "&fgd";
  prompt "&fgd";
  tooltip "&fgd";
  bitmap "icons/fgd.png";
  category scadasoft;
}

command BgdColor {
  label "&bgd";
  prompt "&bgd";
  tooltip "&bgd";
  bitmap "icons/bgd.png";
  category scadasoft;
}

command SetDialoguePath {
  label "&DialoguePath";
  prompt "&DialogPathPrompt";
  bitmap "icons/icrenss.png";
  category scadasoft;
}

command ScriptEditor {
  label "&ScriptEditor";
  prompt "&ScriptEditorPrompt";
  bitmap "icons/script.png";
  category scadasoft;
}

command FormulaEditor {
  label "&FormulaEditor";
  prompt "&FormulaEditorPrompt";
  bitmap "icons/formula.png";
  category scadasoft;
}

command ShowScsInfo {
  label   "&ScsInfo";
  prompt  "&ScsInformation";
  bitmap   "pnlstudio/icons/toupiel.png";
  category scadasoft;
}

command QuitScsStudio {
  label   "&menu_scsquit";
  acceleratorText "Ctrl+Q";
  acceleratorDefinition "<Ctrl><Key Q>";
  prompt  "&quitScsEditor";
  bitmap  "icquit";
  category studio;
  category scadasoft;
}
