// --------------------------------------------------------------------------
// Dss Studio commands
// --------------------------------------------------------------------------

command QuitDssStudio {
  acceleratorText "Ctrl+Q";
  acceleratorDefinition "<Ctrl><Key Q>";
  label   "&menu_scsquit";
  prompt  "&quitScsEditor";
  bitmap  "icquit";
  category studio;
  category scadasoft;
}

command AddDssStep {
  label   "&AddDssStep";
  tooltip "&ttAddDssStep";
  prompt  "&promptAddDssStep";
  bitmap  "icrun";
  category DssStudio;
}

command NewDssScenario {
  label   "&NewDssScenario";
  tooltip "&ttNewDssScenario";
  prompt  "&promptNewDssScenario";
  bitmap  "ivstudio/grapher/icgrapher.png";
  category DssStudio;
}

command GenerateAnimatorFiles {
  label   "&GenerateAnimatorFiles";
  tooltip "&ttGenerateAnimatorFiles";
  prompt  "&promptGenerateAnimatorFiles";
  bitmap  "anstudio/icons/anedt.png";
  category DssStudio;
}

command CheckScenarioConsistency {
  label   "&CheckScenarioConsistency";
  tooltip "&ttCheckScenarioConsistency";
  prompt  "&promptCheckScenarioConsistency";
  bitmap  "ivstudio/icons/icpci.png";
  category DssStudio;
}

command SelectOrientedLinkMode {
  label   "&SelectOrientedLinkMode";
  tooltip "&ttSelectOrientedLinkMode";
  prompt  "&promptSelectOrientedLinkMode";
  bitmap  "dssstudio/icons/link.png";
  category DssStudio;
}

command SelectPolylineLinkMode {
  label   "&SelectPolylineLinkMode";
  tooltip "&ttSelectPolylineLinkMode";
  prompt  "&promptSelectPolylineLinkMode";
  bitmap  "dssstudio/icons/polylink.png";
  category DssStudio;
}
