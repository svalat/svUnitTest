######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 05/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#install in prefix/bin
set(SVUNITTEST_XSTL_DIR ${CMAKE_INSTALL_PREFIX}/share/svUnitTest)
configure_file(svutxmlrun.in svutxmlrun ESCAPE_QUOTES @ONLY)
install(PROGRAMS svutxmlmerger ${CMAKE_CURRENT_BINARY_DIR}/svutxmlrun DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
