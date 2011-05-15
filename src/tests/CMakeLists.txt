######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 05/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

include_directories (../lib/ ../lib/formatters ../lib/listeners ../lib/core ../lib/runner ./ ./helper)

add_definitions(-DTEST_SRC_BASE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/helper")

########### SETUP HELPER MODE #################
set(ENABLE_SELF_TEST no CACHE BOOL "Use the svUnitTest to compile its own test suite.")
if (ENABLE_SELF_TEST)
	############ LIB WITH MAIN AND EXTRA ###########
	set(svutUnitTestBase_SRCS UnitTestMockResultFormatter.cpp
		UnitTestMockTestCase.cpp UnitTestMockListener.cpp
		UnitTestMockTestCase2.cpp)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/selftest)
else (ENABLE_SELF_TEST)
	if (CPPUNIT_FOUND)
		############ LIB WITH MAIN AND EXTRA ###########
		set(svutUnitTestBase_SRCS UnitTestMockResultFormatter.cpp
			UnitTestMockTestCase.cpp UnitTestMockListener.cpp UnitTestMain.cpp
			UnitTestExtra.cpp UnitTestMockTestCase2.cpp)
	else (CPPUNIT_FOUND)
		############ LIB WITH MAIN AND EXTRA ###########
		set(svutUnitTestBase_SRCS UnitTestMockResultFormatter.cpp
			UnitTestMockTestCase.cpp UnitTestMockListener.cpp
			UnitTestMockTestCase2.cpp)
		include_directories(${CMAKE_CURRENT_SOURCE_DIR}/fakecppunit)
		set(CPPUNIT_LIBRARY fakecppunit)
	endif (CPPUNIT_FOUND)
endif(ENABLE_SELF_TEST)

############# BUILD ALL TESTS ##################
macro (build_svunittest_test)
	IF (TEST_COVERAGE) ############ HERE THE CASE FOR COVERAGE
		set(svutUnitTest_ALLSRC)
		set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
		foreach(i ${ARGV})
			list(APPEND svutUnitTest_ALLSRC UnitTest_${i}.cpp)
		endforeach(i)
		add_executable(all_tests ${svutUnitTest_ALLSRC})
		target_link_libraries (all_tests svutUnitTestBase svunittest)
		if (CPPUNIT_FOUND)
			target_link_libraries (all_tests ${CPPUNIT_LIBRARY})
		else (CPPUNIT_FOUND)
			target_link_libraries (all_tests fcppunit)
		endif (CPPUNIT_FOUND)
		add_test(all_tests all_tests)
	ELSE (TEST_COVERAGE) ########### HERE THE NORMAL VERSION WITH MULTIPLE EXECUABLE
		#defin test redirection for kdevelop
		foreach(i ${ARGV})
			add_executable (${i} UnitTest_${i}.cpp)
			target_link_libraries (${i} svutUnitTestBase svunittest)
			if (CPPUNIT_FOUND)
				target_link_libraries (${i} ${CPPUNIT_LIBRARY})
			else (CPPUNIT_FOUND)
				target_link_libraries (${i} fcppunit)
			endif (CPPUNIT_FOUND)
			add_test(${i} ${i})
		endforeach(i)
	ENDIF (TEST_COVERAGE)
endmacro(build_svunittest_test)

################ BUILD TESTS ####################
add_subdirectory(helper)
add_subdirectory(formatters)
add_subdirectory(listeners)
add_subdirectory(core)
add_subdirectory(runner)

############# BUILD MAIN TESTS ##################
add_executable(svutDefaultMain UnitTest_defaultMain.cpp)
target_link_libraries (svutDefaultMain svunittest)
add_test(svutDefaultMain svutDefaultMain)
add_test(svutDefaultMainXml svutDefaultMain -m xml)
add_test(svutDefaultMainStd svutDefaultMain -m std)
add_test(svutDefaultMainStdColor svutDefaultMain -m color)

############# BUILD MAIN TESTS ##################
add_executable(svutStandeloneMain UnitTest_svutStandeloneMain.cpp)
target_link_libraries (svutStandeloneMain svunittest)
add_test(svutStandeloneMain svutStandeloneMain)
add_test(svutStandeloneMainXml svutStandeloneMain -m xml)
add_test(svutStandeloneMainColor svutStandeloneMain -m color)
add_test(svutStandeloneMainStd svutStandeloneMain -m std)

############# BUILD MAIN TESTS ##################
add_executable(svutDefaultMainAllMessages UnitTest_defaultMainAllMessages.cpp)
target_link_libraries (svutDefaultMainAllMessages svutUnitTestBase svunittest)

################ SVUNITTESTFAKE #################
add_executable(svUnitTestFake UnitTest_svUnitTestFake.cpp)
target_link_libraries (svUnitTestFake svunittest_fake)
add_test(svUnitTestFake svUnitTestFake)

################# SUBDIRS #######################
if (ENABLE_SELF_TEST)
	add_subdirectory(selftest)
else(ENABLE_SELF_TEST)
	if (NOT CPPUNIT_FOUND)
		add_subdirectory(fakecppunit)
	endif (NOT CPPUNIT_FOUND)
endif(ENABLE_SELF_TEST)
