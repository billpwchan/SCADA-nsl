#!/bin/sh

if [ "$JAVA_HOME" == "" ]; then
	echo "Variable \$JAVA_HOME not set !!"
	exit 1
fi

if [ "$HEARTS_HOME" == "" ]; then
	echo "Variable \$HEARTS_HOME not set !!"
	exit 1
fi

if [ "$SCSHOME" == "" ]; then
	echo "Variable \$SCSHOME not set !!"
	exit 1
fi

LIB=$SCSHOME/hearts/jar
export LIB

LOCALCLASSPATH=$LIB/heartscore.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/heartsplugin.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/hibernate/antlr-2.7.6.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/hibernate/commons-collections-3.1.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/hibernate/dom4j-1.6.1.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/hibernate/hibernate3.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/hibernate/hibernate-jpa-2.0-api-1.0.0.Final.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/hibernate/javassist-3.12.0.GA.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/hibernate/jta-1.1.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/hibernate/slf4j-api-1.6.1.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/jacorb/avalon-framework-4.1.5.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/jacorb/jacorb.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/jacorb/logkit-1.2.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/log4j/log4j.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/slf4j/slf4j-log4j12-1.6.1.jar
LOCALCLASSPATH=$LOCALCLASSPATH:$LIB/jdbc/mysql-connector-java-5.0.4-bin.jar
export LOCALCLASSPATH

export JAVA_PARAM="-server -mx1024M -ss1M -XX:SurvivorRatio=32"
"$JAVA_HOME/bin/java" $JAVA_PARAM -cp $LOCALCLASSPATH -Dapplication.home=$HEARTS_HOME com.thales.scadasoft.hearts.core.business.Launcher $*
