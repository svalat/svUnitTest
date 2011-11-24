######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 05/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#install ressources in ${prefix}/share/svUnitTest
install(DIRECTORY svUnitTest_html DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
install(DIRECTORY svUnitTest_fake DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
