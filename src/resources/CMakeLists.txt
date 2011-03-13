######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0-dev                    #
#            DATE     : 03/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#subdir
add_subdirectory(svUnitTest_fake)

#install ressources in ${prefix}/share/svUnitTest
install(DIRECTORY svUnitTest_html DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
install(DIRECTORY svUnitTest_fake DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
