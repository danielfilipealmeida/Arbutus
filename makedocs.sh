#!/bin/sh

#  makedocs.sh
#  ArbutusEngine
#
#  Created by Daniel Almeida on 10/03/17.
#

DOCUMENTATION_PATH="Documentation"
#headerdoc2html -o $DOCUMENTATION_PATH src/

HEADER_FILES=$(ls src/**/*.hpp)
headerdoc2html -o $DOCUMENTATION_PATH $HEADER_FILES

cd $DOCUMENTATION_PATH
gatherheaderdoc .
