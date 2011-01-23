######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.1.0                        #
#            DATE     : 01/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

# Base source copied from cmake usr/share/cmake/Modules/FindsvUnitTest.cmake
# Thanks to them.

# Find the svUnitTest library
#
#  This module defines the following variables:
#     svUnitTest_FOUND       - True if svUnitTest_INCLUDE_DIR & svUnitTest_LIBRARY are found
#     svUnitTest_LIBRARIES   - Set when svUnitTest_LIBRARY is found
#     svUnitTest_INCLUDE_DIRS - Set when svUnitTest_INCLUDE_DIR is found
#
#     svUnitTest_INCLUDE_DIR - where to find svUnitTest/svutTestCase.h, etc.
#     svUnitTest_LIBRARY     - the svUnitTes library
#

find_path(svUnitTest_INCLUDE_DIR
	NAMES svUnitTest/svutTestCase.h
	PATHS ${svUnitTest_PREFIX}/include
	DOC "The svUnitTest include directory"
)

find_library(svUnitTest_LIBRARY
	NAMES svunittest
	PATHS ${svUnitTest_PREFIX}/lib
	DOC "The svUnitTest library"
)

# handle the QUIETLY and REQUIRED arguments and set svUnitTest_FOUND to TRUE if
# all listed variables are TRUE
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(svUnitTest DEFAULT_MSG svUnitTest_LIBRARY svUnitTest_INCLUDE_DIR)

if(svUnitTest_FOUND)
  set( svUnitTest_LIBRARIES ${svUnitTest_LIBRARY} )
  set( svUnitTest_INCLUDE_DIRS ${svUnitTest_INCLUDE_DIR} )
endif()

mark_as_advanced(svUnitTest_INCLUDE_DIR svUnitTest_LIBRARY)
