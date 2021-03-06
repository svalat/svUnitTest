######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.5.0-dev                    #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C 2.1                 #
######################################################

include_directories (../lib/ ../lib/formatters ../lib/listeners ../lib/core ../lib/runner ../lib/compat ./ ./helper)

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

########## ENABLE JUNIT OUTPUT FILES ###########
#For integration of tests in jenkins, but only in self-test mode
macro (run_svunittest_test test_name)
	#steup wrapper
	if (ENABLE_VALGRIND)
		set(tmp_test_wrapper valgrind --xml=yes --xml-file=${CMAKE_CURRENT_BINARY_DIR}/${test_name}.memcheck.xml --tool=memcheck --leak-check=full --show-reachable=yes)
	else(ENABLE_VALGRIND)
		set(tmp_test_wrapper "")
	endif(ENABLE_VALGRIND)

	#setup output options
	if (ENABLE_JUNIT_OUTPUT)
		if (ENABLE_SELF_TEST)
			set(tmp_test_run_option -m junit_xml -o ${CMAKE_CURRENT_BINARY_DIR}/${test_name}.junit.xml)
		else (ENABLE_SELF_TEST)
			set(tmp_test_run_option "")
		endif (ENABLE_SELF_TEST)
	endif (ENABLE_JUNIT_OUTPUT)

	#gen text command and register
	add_test(${i} ${tmp_test_wrapper} ${CMAKE_CURRENT_BINARY_DIR}/${i} ${tmp_test_run_option})
endmacro (run_svunittest_test)

############# BUILD ALL TESTS ##################
macro (build_svunittest_test)
	IF (TEST_COVERAGE) ############ HERE THE CASE FOR COVERAGE
		set(svutUnitTest_ALLSRC)
		set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
		foreach(i ${ARGV})
			list(APPEND svutUnitTest_ALLSRC UnitTest_${i}.cpp)
		endforeach(i)
		get_filename_component(current_dirname ${CMAKE_CURRENT_SOURCE_DIR} NAME)
		add_executable(all_tests_${current_dirname} ${svutUnitTest_ALLSRC})
		target_link_libraries (all_tests_${current_dirname} svutUnitTestBase svunittest)
		if (NOT ENABLE_SELF_TEST)
			if (CPPUNIT_FOUND)
				target_link_libraries (all_tests_${current_dirname} ${CPPUNIT_LIBRARY})
			else (CPPUNIT_FOUND)
				target_link_libraries (all_tests_${current_dirname} fcppunit)
			endif (CPPUNIT_FOUND)
		endif(NOT ENABLE_SELF_TEST)
		add_test(all_tests_${current_dirname} ${CMAKE_CURRENT_BINARY_DIR}/all_tests_${current_dirname})
	ELSE (TEST_COVERAGE) ########### HERE THE NORMAL VERSION WITH MULTIPLE EXECUABLE
		#defin test redirection for kdevelop
		foreach(i ${ARGV})
			add_executable (${i} UnitTest_${i}.cpp)
			target_link_libraries (${i} svutUnitTestBase svunittest)
			if (NOT ENABLE_SELF_TEST)
				if (CPPUNIT_FOUND)
					target_link_libraries (${i} ${CPPUNIT_LIBRARY})
				else (CPPUNIT_FOUND)
					target_link_libraries (${i} fcppunit)
				endif (CPPUNIT_FOUND)
			endif (NOT ENABLE_SELF_TEST)
			run_svunittest_test(${i})
		endforeach(i)
	ENDIF (TEST_COVERAGE)
endmacro(build_svunittest_test)

################ BUILD TESTS ####################
IF (TEST_COVERAGE)
set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
ENDIF (TEST_COVERAGE)

################ BUILD TESTS ####################
add_subdirectory(helper)
add_subdirectory(formatters)
add_subdirectory(listeners)
add_subdirectory(core)
add_subdirectory(runner)
add_subdirectory(compat)

############# BUILD MAIN TESTS ##################
add_executable(svutDefaultMain UnitTest_defaultMain.cpp)
target_link_libraries (svutDefaultMain svunittest)
add_test(svutDefaultMain ${CMAKE_CURRENT_BINARY_DIR}/svutDefaultMain)
add_test(svutDefaultMainXml ${CMAKE_CURRENT_BINARY_DIR}/svutDefaultMain -m xml)
add_test(svutDefaultMainStd ${CMAKE_CURRENT_BINARY_DIR}/svutDefaultMain -m std)
add_test(svutDefaultMainStdColor ${CMAKE_CURRENT_BINARY_DIR}/svutDefaultMain -m color)
add_test(svutDefaultMainJUnitXML ${CMAKE_CURRENT_BINARY_DIR}/svutDefaultMain -m junit_xml)
add_test(svutDefaultMainQtXML ${CMAKE_CURRENT_BINARY_DIR}/svutDefaultMain -m qt_xml)

############# BUILD MAIN TESTS ##################
add_executable(svutStandeloneMain UnitTest_svutStandeloneMain.cpp)
target_link_libraries (svutStandeloneMain svunittest)
add_test(svutStandeloneMain ${CMAKE_CURRENT_BINARY_DIR}/svutStandeloneMain)
add_test(svutStandeloneMainXml ${CMAKE_CURRENT_BINARY_DIR}/svutStandeloneMain -m xml)
add_test(svutStandeloneMainColor ${CMAKE_CURRENT_BINARY_DIR}/svutStandeloneMain -m color)
add_test(svutStandeloneMainStd ${CMAKE_CURRENT_BINARY_DIR}/svutStandeloneMain -m std)

############# BUILD MAIN TESTS ##################
add_executable(svutDefaultMainAllMessages UnitTest_defaultMainAllMessages.cpp)
target_link_libraries (svutDefaultMainAllMessages svutUnitTestBase svunittest)

############# BUILD MAIN TESTS ##################
add_executable(flatMode UnitTest_flatMode.cpp)
target_link_libraries (flatMode svutUnitTestBase svunittest)

############# BUILD MAIN TESTS ##################
add_executable(flatFixtures UnitTest_flatFixtures.cpp)
target_link_libraries (flatFixtures svutUnitTestBase svunittest)

############# BUILD MAIN TESTS ##################
add_executable(fakeFlatFixture UnitTest_fakeFlatFixture.cpp)
target_link_libraries (fakeFlatFixture svutUnitTestBase svunittest)

################ SVUNITTESTFAKE #################
add_executable(svUnitTestFake UnitTest_svUnitTestFake.cpp)
add_test(svUnitTestFake ${CMAKE_CURRENT_BINARY_DIR}/svUnitTestFake)

################ SVUNITTESTFAKE #################
add_executable(svUnitTestFakeMulti UnitTest_svUnitTestFake.cpp UnitTest_svUnitTestFake2.cpp)
add_test(svUnitTestFakeMulti ${CMAKE_CURRENT_BINARY_DIR}/svUnitTestFakeMulti)

################# SUBDIRS #######################
if (ENABLE_SELF_TEST)
	add_subdirectory(selftest)
else(ENABLE_SELF_TEST)
	if (NOT CPPUNIT_FOUND)
		add_subdirectory(fakecppunit)
	endif (NOT CPPUNIT_FOUND)
endif(ENABLE_SELF_TEST)
