#!/bin/bash

for tmp in `cat pagelist.txt`
do
	curl "http://localhost:8080/trac/wiki/${tmp}?format=doxygen" > ${tmp}.dox
done
