#!/bin/bash
######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0-dev                    #
#            DATE     : 02/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

########################## VARIABLES ###########################
old_version="$1"
new_version="$2"

######################### CHECK ARGS ###########################
#check parameter
if [ -z "$old_version" ] || [ -z "$new_version" ]; then
	echo "Usage : $0 {old_version} {new_version}"
	echo
	echo "Version format : major.minor.release[-dev|-rc1]"
	echo
	exit 1
fi

########################## FUNCTION ############################
#check format
#params :
#  - $1 : version value to check
function check_version_format()
{
	if [ -z "`echo \"$1\" | egrep '^[0-9]+\.[0-9]+\.[0-9]+(-dev|-rc[0-9]+)?$'`" ]
	then
		echo "Error : Invalid version format : $1"
		echo "        Must be major.minor.release[-dev|-rc1]"
		exit 1
	fi
}

########################## FUNCTION ############################
#check exec dir to force execution from project root dir
function check_exec_dir()
{
	if [ ! -f dev-scripts/update_version_number.sh ] || [ ! -f ChangeLog.txt ] || [ ! -f COPYING-FR.txt ] ; then
		echo "Error: this script must be executed from project root dir as ./dev-scripts/update_version_number.sh"
		exit 1
	fi
}

########################## FUNCTION ############################
#get list of source files in which to update version
#params :
function get_file_list()
{
	git ls-files
}

########################## FUNCTION ############################
#update version in cpp headers
#params :
#   -$1 : old version
#   -$2 : new version
function update_version_cpp_headers()
{
	for file in `get_file_list`
	do
		sed -i "s/^             VERSION  : $1\$/             VERSION  : $2/g" "$file"
	done
}

########################## FUNCTION ############################
#update date in cpp headers
#params :
function update_date_cpp_headers()
{
	new_date=`date +%m/%Y`
	for file in `get_file_list`
	do
		sed -i -r "s@^             DATE     : [0-9]{2}/[0-9]{4}\$@             DATE     : ${new_date}@g" "$file"
	done
}

########################## FUNCTION ############################
#update version in script headers
#params :
#   -$1 : old version
#   -$2 : new version
function update_version_script_headers()
{
	orig=`printf "#            VERSION  : %-20s         #" "$1"`
	dest=`printf "#            VERSION  : %-20s         #" "$2"`
	for file in `get_file_list`
	do
		sed -i "s/^${orig}\$/${dest}/g" "$file"
	done
}

########################## FUNCTION ############################
#update date in scripts headers
#params :
function update_date_script_headers()
{
	new_date=`date +%m/%Y`
	for file in `get_file_list`
	do
		sed -i -r "s@^#            DATE     : [0-9]{2}/[0-9]{4}                      #\$@#            DATE     : ${new_date}                      #@g" "$file"
	done
}

########################## FUNCTION ############################
#update version in root CMakeLists.txt
#params :
#   -$1 : old version
#   -$2 : new version
function update_version_exotic_files()
{
	#root CMakeLists.txt (to define version of project)
	sed -i "s/^set(svUnitTest_VERSION \"$1\")\$/set(svUnitTest_VERSION \"$2\")/g" CMakeLists.txt
	#Doxyfile
	sed -i "s/^PROJECT_NUMBER         = $1\$/PROJECT_NUMBER         = $2/g" Doxyfile
	#pkg-config template
	sed -i "s/Version: $1/Version: $2/g" src/integration/pkg-config/svUnitTest.pc.in
	#define version in svUnitTest.h
	sed -i "s/^#define SVUT_LIBARY_VERSION \"$1\"\$/#define SVUT_LIBARY_VERSION \"$2\"/g" src/lib/svUnitTest.h
	#xml output definition
	for file in src/lib/svutResultFormatterQtXml.cpp src/test/UnitTest_svutResultFormatterQtXml.cpp
	do
		sed -i "s#<svUnitTestVersion>$1</svUnitTestVersion>#<svUnitTestVersion>$2</svUnitTestVersion>#g" -i "$file"
	done
	#gollum update script
	sed -i "s/echo \"             VERSION  : $1\"/echo \"             VERSION  : $2\"/g" src/doxygen/update_from_gollum.sh
	#configure.in example
	sed -i "s/$1/$2/g" src/examples/build_with_autotools/configure.in
}

########################## FUNCTION ############################
#update date in exotic files
#params:
function update_date_exotic_files()
{
	new_date=`date +%m/%Y`
	#gollum update script
	sed -i -r "s@echo \"             DATE     : [0-9]{2}/[0-9]{4}\"@echo \"             DATE     : ${new_date}\"@g" src/doxygen/update_from_gollum.sh
}

########################## FUNCTION ############################
#Display version not update in case of new files not supported by the script
#params :
#  - $1 : old version
function display_version_not_updated()
{
	echo "--------------------- Not updated : -------------------------"
	grep --color -R -I "$1" `git ls-files`
	echo "-------------------------------------------------------------"
}

############################ MAIN ##############################
#check
check_version_format "$old_version"
check_version_format "$new_version"
check_exec_dir
#update headers
update_version_cpp_headers "$old_version" "$new_version"
update_version_script_headers "$old_version" "$new_version"
update_version_exotic_files "$old_version" "$new_version"
update_date_cpp_headers
update_date_script_headers
update_date_exotic_files
display_version_not_updated "$old_version"
