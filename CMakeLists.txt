######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.1.0                        #
#            DATE     : 01/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#project definition
cmake_minimum_required (VERSION 2.6)
project(svUnitTest CXX)
set(svUnitTest_VERSION "0.1.0")

#load cmake modules
include(CheckIncludeFileCXX)

#deps
include(cmake/FindCppUnit.cmake)

#global setup
enable_testing()
add_definitions(-DVERSION="${svUnitTest_VERSION}")

#checks
CHECK_INCLUDE_FILE_CXX(argp.h HAVE_ARGP_H)

#message
if (NOT HAVE_ARGP_H)
  message(FATAL_ERROR "Can't find file 'argp.h' required for svUnitTest, please look at you glibc paths...")
endif (NOT HAVE_ARGP_H)

#subdirs
add_subdirectory (src)

#CPACK support
INCLUDE(InstallRequiredSystemLibraries)
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "C++ unit test library.")
SET(CPACK_PACKAGE_VENDOR "Sébastien Valat")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ReadMe.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING-EN.txt")
SET(CPACK_PACKAGE_VERSION_MAJOR "0")
SET(CPACK_PACKAGE_VERSION_MINOR "0")
SET(CPACK_PACKAGE_VERSION_PATCH "2")
SET(CPACK_PACKAGE_INSTALL_DIRECTORY "CMake ${CMake_VERSION_MAJOR}.${CMake_VERSION_MINOR}")
SET(CPACK_GENERATOR "TGZ;TBZ2;DEB")
SET(CPACK_PACKAGE_CONTACT "Sébastien Valat <sebastien.valat.dev@orange.fr>")
INCLUDE(CPack)

