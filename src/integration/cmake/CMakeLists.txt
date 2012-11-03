######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.5.0-dev                    #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#Generate and install cmake module file
configure_file(FindsvUnitTest.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/FindsvUnitTest.cmake ESCAPE_QUOTES @ONLY)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/FindsvUnitTest.cmake DESTINATION share/cmake/Modules/)
