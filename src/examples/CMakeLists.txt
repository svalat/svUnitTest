######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.5.0-dev                    #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C 2.1                 #
######################################################

#install examples
set(examples_DIRS build_with_cmake build_with_makefile build_with_pkg-config std_string test_suite
	build_with_autotools)

foreach(i ${examples_DIRS})
	install(DIRECTORY ${i} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest/examples
		FILES_MATCHING PATTERN "*")
	install(FILES Makefile DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest/examples)
endforeach(i)
