######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.5.0-dev                    #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C 2.1                 #
######################################################

#install in prefix/bin
set(SVUNITTEST_XSTL_DIR ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
configure_file(svutxmlrun.in ${CMAKE_CURRENT_BINARY_DIR}/svutxmlrun ESCAPE_QUOTES @ONLY)
install(PROGRAMS svutxmlmerger svutserver ${CMAKE_CURRENT_BINARY_DIR}/svutxmlrun DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
