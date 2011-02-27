######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.2.0                        #
#            DATE     : 02/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#install examples
set(examples_DIRS build_with_cmake build_with_makefile build_with_pkg-config std_string test_suite)

foreach(i ${examples_DIRS})
	install(DIRECTORY ${i} DESTINATION ${CMAKE_INSTALL_PREFIX}/share/svUnitTest/examples
		FILES_MATCHING PATTERN "*.h"
		PATTERN "*.cpp"
		PATTERN "Makefile"
		PATTERN "*.txt"
		PATTERN "*.cmake"
		PATTERN "*.sh"
		PATTERN "build" EXCLUDE)
endforeach(i)
