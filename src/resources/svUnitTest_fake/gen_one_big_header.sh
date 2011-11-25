#!/bin/bash
######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 05/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#print file by commenting internal includes
#in order :
MERGE_FILES="svUnitTest.h svutExAssert.h svutAsserter.h svutAssert.h svutTestCase.h svutFlatTestCase.h svutDefaultMain.h"

#check all before
for f in $MERGE_FILES
do
	if [ ! -f include/svUnitTest/$f ]; then
		echo "Invalid file : include/svUnitTest/$f" 1>&2
		exit 1
	fi
done

#gen merged file
for f in $MERGE_FILES
do
	cat include/svUnitTest/$f | sed -e 's!#include "!//include "!g'
	echo
done
