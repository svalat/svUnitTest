######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.4.0                        #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#Generate and install pkg-config file
configure_file(svUnitTest.pc.in ${CMAKE_CURRENT_BINARY_DIR}/svUnitTest.pc ESCAPE_QUOTES @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/svUnitTest.pc DESTINATION share/pkgconfig)
