Boite de commande du compilo Vc 2010

set TCLDIR=D:/softs2010/tcltk859/tcl8.5.9

cd D:\softs2010\tcl8.6.9\tcl8.5.9\win
si necessaire forcer BUILDDIRTOP =msvc$(VCVER) 
Idem pour tk859



Dans D:\softs2010\tcltk859\tcl8.5.9\win; faire
nmake -f makefile.vc
nmake -f makefile.vc install

idem dans  D:\softs2010\tcltk859\tk8.5.9\win

Voir les fichiers installer dans  dans C:\Program Files\Tcl
Recopier 


Creer un repertoire bin (scsidlgen contient $TCLHOME/bin!!!


TCL_LIBRARY et TCLLIBPATH au format UNIX
set TCLLIBPATH=D:/softs2010/tcltk86_sourceforge/library

set TCL_LIBRARY=D:/softs2010/tcltk86_sourceforge/library

Recopier dans include livraison TclInt.h et TclintDecls/h: a prendre dans repertoire  generic




