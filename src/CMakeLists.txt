######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.2.0                        #
#            DATE     : 02/2011                      #
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
install(DIRECTORY svUnitTest_html DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
