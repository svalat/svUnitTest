#!/bin/bash

GOLLUM_DIR="$1"

if [ -z "$GOLLUM_DIR" ]; then
	echo "USAGE: $0 {gollum_dir}"
	exit 1
fi

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
	golum_to_doxygen ${GOLLUM_DIR}/$tmp > $outname || exit 1
done

echo " * DONE"
