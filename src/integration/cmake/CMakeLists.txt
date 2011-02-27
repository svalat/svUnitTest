######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.2.0                        #
#            DATE     : 02/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#Generate and install cmake module file
configure_file(FindsvUnitTest.cmake.in FindsvUnitTest.cmake ESCAPE_QUOTES @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/FindsvUnitTest.cmake DESTINATION share/cmake/Modules/)
