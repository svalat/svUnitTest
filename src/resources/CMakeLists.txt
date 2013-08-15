######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.5.0-dev                    #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C 2.1                 #
######################################################

#install ressources in ${prefix}/share/svUnitTest
install(DIRECTORY svUnitTest_html DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
install(DIRECTORY svUnitTest_fake DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
