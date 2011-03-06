#!/bin/bash

GOLLUM_DIR="$1"

if [ -z "$GOLLUM_DIR" ]; then
	echo "USAGE: $0 {gollum_dir}"
	exit 1
fi

function print_header()
{
	echo "/*****************************************************"
	echo "             PROJECT  : svUnitTest"
	echo "             VERSION  : 0.3.0-dev"
	echo "             DATE     : 03/2011"
	echo "             AUTHOR   : Valat Sébastien"
	echo "             LICENSE  : CeCILL-C"
	echo "*****************************************************/"
}

echo " * GOLLUM_DIR : ${GOLLUM_DIR}"
echo " * Import images from gollum..."
for tmp in ${GOLLUM_DIR}/images/*.dot
do
	echo " * Import `basename $tmp`..."
	cp $tmp images/`basename $tmp`
done

echo

for tmp in `cat pagelist.txt | grep .md`
do
	outname=`echo $tmp | sed -e s/.md/.dox/g`
	echo " * Convert $tmp to $outname ..."

	print_header > $outname || exit 1
	golum_to_doxygen ${GOLLUM_DIR}/$tmp >> $outname || exit 1
done

echo " * DONE"
