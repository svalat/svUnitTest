######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.1.0                        #
#            DATE     : 01/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#subdirs
add_subdirectory (lib)
add_subdirectory (integration)
add_subdirectory (examples)
if (NOT DISABLE_UNIT_TESTS)
	add_subdirectory (test)
endif(NOT DISABLE_UNIT_TESTS)
install(DIRECTORY xslt_html DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)