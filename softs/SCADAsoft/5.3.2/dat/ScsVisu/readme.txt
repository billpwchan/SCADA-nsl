EB 17 nov 1999

****************************************************************************************
DESCRIPTION OF DATA DIRECTORIES:
****************************************************************************************

-PanelBuilder 
	.stills there for compatibilty 
	( must be suppressed once the Ilog Views 31 version is integrated for all platforms)

-ilog (not managed by RCS)
	- NoVersion
		_ data :is the exact copy of the current ilog views distribution data dir.
		  (i.e $ILVHOME/data) 			
		_ studio : is the exact copy of the current ilog views studio distribution data dir.
		  (i.e $ILVHOME/studio) only the data directory is mandatory the others must be deleted.	

NB :
Never delete the Ilog/300 directory :
this one is not the exact copy of the original ilog 300 distrib , and contains 
modified materiels, that are essentials for any version with views 30xx version.


scsstudio:
	_ pnlstudio : contains pnlstudio data , managed by RCS
	_ dssstudio : contains dssstudio data , managed by RCS


*****************************************************************************************
DATABASE MESSAGE MANAGEMENT
*****************************************************************************************
To understand clearly the management of DBM files, please refer to 
Ilog Views USER Manual / Message database Part.
Languages managed are en_US, fr_FR.

The current procedure (CheckDbmDirectory) must be applied to all the directories below :


Description of the procedure CheckDbmDirectory
----------------------------------------------
CheckDbmDirectory( DIR, DBMFILE)
1) go in DIR
2) check that DBMFILE exists with language en_US
3) for each different language/OS distribution
	3.1) Check that the locale/ISO-distribution-name/DBMFILE exists with the right language.
	3.2) If not create the directory ( see names in Ilog views doc), create DBMFILE with the right language
	    ( ilog studio message utility can be used)  


(Directories, DbmFiles) to check:
--------------------
ilog/NoVersion/data/ilviews | views.dbm
ilog/NoVersion/studio/data  | studio.dbm
scsstudio/pnlstudio         | pnlstudio.dbm
scsstudio/dssstudio         | dssstudio.dbm
scsstudio/ansstudio         | image.dbm
scsstudio/ansstudio         | launcher.dbm
scsstudio/ansstudio         | symbol..dbm

Example of application
----------------------
We use views.dbm in 4 different contexts

***************************************
*	OS	|	language      *
***************************************
	windows 	en_US
	windows 	fr_FR
	unix	 	en_US
	unix	 	fr_FR

The windows en_US will be mixed together (Ilog views rule)
So we will have to check :

views.dbm in language en_US in ilog/NoVersion/data/ilviews
views.dbm in language fr_FR in ilog/NoVersion/data/ilviews/loacle/fr_FR.windows-1252 ( windows context)
views.dbm in language fr_FR in ilog/NoVersion/data/ilviews/loacle/fr_FR.ISO-8859-1   ( unix context)



