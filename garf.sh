#!/bin/bash
# $@ - all command line params
# $1 - first param
# $# - number of command line params
# java -cp out/production/garfield:out/production/nconsole -Djava.library.path=cmake-build-debug Garfield $@
java -cp out/production/garfield:out/production/nconsole -Djava.library.path=cmake-build-debug -agentlib:jdwp=transport=dt_socket,server=y,suspend=n,address=5005 Garfield $@
