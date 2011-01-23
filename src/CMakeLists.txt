######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.1.0                        #
#            DATE     : 01/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#subdirs
add_subdirectory (lib)
add_subdirectory (test)
add_subdirectory (integration)
add_subdirectory (examples)
install(DIRECTORY xslt_html DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
