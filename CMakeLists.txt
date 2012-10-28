######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 05/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

######################################################
#project definition
cmake_minimum_required (VERSION 2.6)
project(svUnitTest CXX)
set(svUnitTest_VERSION "0.3.0")

######################################################
#load cmake modules
include(CheckIncludeFileCXX)

######################################################
#global setup
enable_testing()
add_definitions(-DVERSION="${svUnitTest_VERSION}")

######################################################
#declare user options
set(ENABLE_SELF_TEST no CACHE BOOL "Permit to use svUnitTest to run its own tests in place of cppunit.")
set(ENABLE_JUNIT_OUT no CACHE BOOL "Generate a JUnit XML file for each test while running svUnitTest test suite.")
set(ENABLE_VALGRIND no CACHE BOOL "Wrap all test execution with valgrind memcheck to generate XML report for each one.")
set(DISABLE_TESTS no CACHE BOOL "Disable compilation of svUnitTest tests.")
set(DISABLE_CPPUNIT no CACHE BOOL "Permit to disable compilation of unit tests on top of cppunit framework, use a fake remplacement.")

######################################################
#deps
if (NOT DISABLE_CPPUNIT)
include(cmake/FindCppUnit.cmake)
endif (NOT DISABLE_CPPUNIT)

#checks
CHECK_INCLUDE_FILE_CXX(unistd.h HAVE_UNISTD_H)

#setup definitions for unitstd.h
if (HAVE_UNISTD_H)
	add_definitions(-DHAVE_UNISTD_H)
endif (HAVE_UNISTD_H)

######################################################
#Display info on current configuration
macro (print_variable_status var_name)
	if (${var_name})
		message(STATUS "${var_name} : yes")
	else (${var_value})
		message(STATUS "${var_name} : no")
	endif (${var_name})
endmacro (print_variable_status)

#Display info on current configuration
print_variable_status("HAVE_UNISTD_H")
print_variable_status("ENABLE_SELF_TEST")
print_variable_status("ENABLE_JUNIT_OUT")
print_variable_status("ENABLE_VALGRIND")
print_variable_status("DISABLE_TESTS")
print_variable_status("DISABLE_CPPUNIT")

######################################################
#subdirs
add_subdirectory (src)

######################################################
#CPACK support
INCLUDE(InstallRequiredSystemLibraries)
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "C++ unit test library.")
SET(CPACK_PACKAGE_VENDOR "Sébastien Valat")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING-EN.txt")
SET(CPACK_PACKAGE_VERSION "0.3.0")
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "3")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
SET(CPACK_GENERATOR "TGZ;TBZ2;DEB")
SET(CPACK_PACKAGE_CONTACT "Sébastien Valat <sebastien.valat.dev@orange.fr>")
INCLUDE(CPack)
