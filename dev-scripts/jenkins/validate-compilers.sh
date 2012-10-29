#!/bin/sh
######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 10/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

######################################################
# This script serve to validate all compiler configurations
# into jenkins.

######################################################
# Default values
STANDARD=''
COMPILER=''
BUILD_MODE=''
HELP_MESSAGE="Usage : $0 --std={default|c++0x|c++11} --cxx={g++-...|icpc|clang++} --mode={std|pedantic|pedantic-werror}"

######################################################
# Parse arguments
for arg in "$@"; do
	case "$arg" in
		--std=*)
			STANDARD=`echo "$arg" | sed -e 's/^--std=//g'`
			;;
		--cxx=*)
			COMPILER=`echo "$arg" | sed -e 's/^--cxx=//g'`
			;;
		--mode=*)
			BUILD_MODE=`echo "$arg" | sed -e 's/^--mode=//g'`
			;;
		*)
			echo "Invalid argument : $arg" 1>&2
			echo "${HELP_MESSAGE}" 1>&2
			exit 1
			;;
	esac
done

######################################################
# Check that we have all arguments
if [ -z "${STANDARD}" ] || [ -z "${COMPILER}" ] || [ -z "${BUILD_MODE}" ]; then
	echo "Missing argument." 1>&2
	echo "${HELP_MESSAGE}" 1>&2
	exit 1
fi

######################################################
#setup debug mode, so commands are printed and stop on errors
set -e
set -x

# Remove old build and install files
rm -rf install
rm -rf build

#create build dir
mkdir build
cd build

cflags=''

case $BUILD_MODE in
    std)              cflags='';;
    pedantic)         cflags='-pedantic -Wall';;
    pedantic-werror)  cflags='-pedantic -Wall -Werror';;
    *)
         echo "Unknown mode $BUILD_MODE"; exit 1;;
esac

if [ ! -z "${STANDARD}" ] && [ "${STANDARD}" != 'default' ]; then
    cflags="${cflags} -std=${STANDARD}"
fi

#Temporary fix due to bug in clang++ with stdc++ lib from gcc
if [ "${STANDARD}" != 'default' ] && [ "${COMPILER}" = 'clang++' ]; then
    cflags="${cflags} -U__GXX_EXPERIMENTAL_CXX0X__"
fi

#clang warn on typof for default C++
if [ "${STANDARD}" = 'default' ] && [ "${COMPILER}" = 'clang++' ] && [ "${BUILD_MODE}" = 'pedantic-werror' ]; then
    cflags="-Wno-language-extension-token"
fi

#Configure for build
cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=${COMPILER} -DCMAKE_CXX_FLAGS="${cflags}" -DENABLE_SELF_TEST='yes' -DCMAKE_INSTALL_PREFIX=$PWD/../install -DENABLE_JUNIT_OUTPUT='yes'

#build / test / install
make
#make test
ctest -D ExperimentalTest --no-compress-output
cp Testing/`head -n 1 Testing/TAG`/Test.xml ./CTestResults.xml
make install
