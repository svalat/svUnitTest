######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0-dev                    #
#            DATE     : 03/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#Generate and install pkg-config file
configure_file(svUnitTest.pc.in svUnitTest.pc ESCAPE_QUOTES @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/svUnitTest.pc DESTINATION share/pkgconfig)
