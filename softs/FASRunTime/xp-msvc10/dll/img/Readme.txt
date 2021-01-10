to use MyInputMgr.exe :

- save libimgrSigHILC.dll in $SCSHOME/$SYSTEM/dll/img/
- set environment variable IMGR_LIBPATH=$SCSHOME/$SYSTEM/dll/img/
- Modify ScsEnvTable to use MyInputMgr instead of inputmgr.exe
- MyInputMgr should load libimgrSigHILC.dll at runtime and able to ADDTRYBIND SigHILCServer


