######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0-dev                    #
#            DATE     : 03/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#project definition
cmake_minimum_required (VERSION 2.6)
project(svUnitTest CXX)
set(svUnitTest_VERSION "0.3.0-dev")

#load cmake modules
include(CheckIncludeFileCXX)

#deps
set(DISABLE_CPPUNIT no CACHE BOOL "Permit to disable compilation of unit tests on top of cppunit framework.")
if (NOT DISABLE_CPPUNIT)
include(cmake/FindCppUnit.cmake)
endif (NOT DISABLE_CPPUNIT)

#global setup
enable_testing()
add_definitions(-DVERSION="${svUnitTest_VERSION}")

#checks
CHECK_INCLUDE_FILE_CXX(unistd.h HAVE_UNISTD_H)

#setup definitions for unitstd.h
if (HAVE_UNISTD_H)
	add_definitions(-DHAVE_UNISTD_H)
endif (HAVE_UNISTD_H)

#subdirs
add_subdirectory (src)

#CPACK support
INCLUDE(InstallRequiredSystemLibraries)
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "C++ unit test library.")
SET(CPACK_PACKAGE_VENDOR "Sébastien Valat")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING-EN.txt")
SET(CPACK_PACKAGE_VERSION "0.3.0-dev")
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "3")
SET(CPACK_PACKAGE_VERSION_PATCH "0")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
SET(CPACK_GENERATOR "TGZ;TBZ2;DEB")
SET(CPACK_PACKAGE_CONTACT "Sébastien Valat <sebastien.valat.dev@orange.fr>")
INCLUDE(CPack)

