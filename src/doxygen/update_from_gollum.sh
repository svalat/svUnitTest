#!/bin/bash
######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 10/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

######################################################
#Store args
GOLLUM_DIR="$1"

######################################################
#Check args
if [ -z "$GOLLUM_DIR" ]; then
	echo "USAGE: $0 {gollum_dir}" 1>&2
	exit 1
fi

######################################################
#check exec dir
if [ ! -f './update_from_gollum.sh' ]; then
	echo "Need to be executed in doxygen directory." 1>&2
	exit 1
fi

######################################################
#Add header to all .dox files
function print_header()
{
	echo "/*****************************************************"
	echo "             PROJECT  : svUnitTest"
	echo "             VERSION  : 0.3.0"
	echo "             DATE     : 05/2011"
	echo "             AUTHOR   : Valat Sébastien"
	echo "             LICENSE  : CeCILL-C"
	echo "*****************************************************/"
}

######################################################
echo " * GOLLUM_DIR : ${GOLLUM_DIR}"

######################################################
#Compile the gollum_to_doxygen exe
g++ ../../dev-scripts/golum_to_doxygen.cpp -o ./golum_to_doxygen

#Cleanup old files to ensure full sync
echo " * Cleanup"
rm -f -v *.dox
rm -rf -v images/*

#Import DOT images
echo " * Import DOT images from gollum..."
for tmp in ${GOLLUM_DIR}/images/*.dot
do
	echo " * Import `basename $tmp`..."
	cp $tmp images/`basename $tmp`
done

#Import images/screenshots
echo " * Import PNG images from gollum..."
for tmp in screenshots
do
	echo " * Import $tmp"
	cp -r ${GOLLUM_DIR}/images/$tmp images/$tmp
done

echo

#Now import all the pages
for tmp in `grep .md ./pagelist.txt`
do
	#check if file exist
	if [ ! -f "${GOLLUM_DIR}/$tmp" ]; then
		echo "ERROR : file doesn't exist : ${GOLLUM_DIR}/$tmp" 1>&2
		exit 1
	fi

	#compute names
	outname=`echo $tmp | sed -e s/.md/.dox/g`
	echo " * Convert $tmp to $outname ..."

	#do conversion
	print_header > $outname || exit 1
	./golum_to_doxygen ${GOLLUM_DIR}/$tmp >> $outname || exit 1
done

echo

#Print ignored pages
for tmp in ${GOLLUM_DIR}/*.md
do
	name=`basename $tmp`
	if [ -z "`grep $name pagelist.txt`" ]; then
		echo " * Ignore $name"
	fi
done

echo

#cleanup tmp exe
echo " * Cleanup tmp ./golum_to_doxygen"
rm -f ./golum_to_doxygen

#Finish
echo " * DONE"
