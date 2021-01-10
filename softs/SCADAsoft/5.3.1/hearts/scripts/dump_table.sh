#!/bin/sh
# MySQL Import cmd (for memory) : 
# %MYSQL_HOME%\bin\mysql --user=%USER% --password=%PSWD% %DATABASE% < %FILENAME%

BAD_ARGUMENT=-1
if [ -z $1 ] ; then
  echo "Invalid parameter"
  echo "usage  :  $0 TABLE_NAME"
  echo "          TABLE_NAME : The name of the table to dump in a file"
  exit $BAD_ARGUMENT
fi

# The name of the TABLE is passed by the HEARTS Server,
# but can be used manually if the user knows the name of the TABLE
TABLE_NAME=$1

# To change depending on project settings
ZIP_EXEC=tar
MYSQL_HOME=/home/jasper/jasperreports-server-cp-4.1.0/mysql
EXPORT_DIR=${ACTIVE_SLOT}/sdo/scspath/TABLE_BACKUP

# To change depending on project settings
USER=hearts
PSWD=hearts
DATABASE=hearts

# Fixed part of the script
CURRENT_DATE=$(date +%Y%m%d)
CURRENT_TIME=$(date +%H%M%S)

# Create a specific folder named by the current date
EXPORT_DIR=$EXPORT_DIR/$2$CURRENT_DATE
if [ ! -d $EXPORT_DIR ] ; then
    mkdir -p $EXPORT_DIR
fi

#FILENAME="$EXPORT_DIR/$TABLE_NAME#$CURRENT_DATE$CURRENT_TIME"
FILENAME="$TABLE_NAME#$CURRENT_DATE$CURRENT_TIME"
SQLFILENAME=$FILENAME.sql
ZIPFILENAME=$FILENAME.tgz

$MYSQL_HOME/bin/mysqldump --socket=/var/lib/mysql/mysql.sock --user=$USER --password=$PSWD $DATABASE $TABLE_NAME > $SQLFILENAME
echo "The TABLE $TABLE_NAME has been saved in the file $SQLFILENAME."

$ZIP_EXEC -zcf $EXPORT_DIR/$ZIPFILENAME $SQLFILENAME
echo "Compress the file $SQLFILENAME in the archive file $ZIPFILENAME."

rm -rf $SQLFILENAME
echo "Remove the file $SQLFILENAME."





