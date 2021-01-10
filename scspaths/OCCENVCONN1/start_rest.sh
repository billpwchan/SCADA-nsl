#!/bin/bash
arg1=$1
arg2=$2

physenv=${arg2:2}
srvname=${arg1:2}

SCS_ARGS="-Dscadasoft.servername=${srvname} -Dscadasoft.physicalenv=${physenv} -Dscadasoft.remote.envname=SRV1"


JAVA_OPTS="-Xms1536M -Xmx1536M -XX:+HeapDumpOnOutOfMemoryError -XX:+PrintGCDetails -XX:+PrintGCTimeStamps -XX:+PrintFlagsFinal"
JAVA_OPTS="${JAVA_OPTS} -Djava.util.logging.config.file=logging.properties"
#JAVA_OPTS="${JAVA_OPTS} -XX:OnError=\"kill %p\" -XX:OnOutOfMemoryError=\"kill %p\""

${JAVA_HOME}/bin/java -agentlib:jdwp=transport=dt_socket,address=localhost:19019,server=y,suspend=n -server ${JAVA_OPTS} -Dloader.path="$(ls -1 rest_plugin/*.jar | paste -sd ",")" ${SCS_ARGS} -jar rest_bin/restgateway*.jar
