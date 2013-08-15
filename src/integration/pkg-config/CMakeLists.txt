######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.5.0-dev                    #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C 2.1                 #
######################################################

#Generate and install pkg-config file
configure_file(svUnitTest.pc.in ${CMAKE_CURRENT_BINARY_DIR}/svUnitTest.pc ESCAPE_QUOTES @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/svUnitTest.pc DESTINATION share/pkgconfig)
