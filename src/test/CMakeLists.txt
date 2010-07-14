include_directories (${svUnitTest_SOURCE_DIR}/src/lib/)

############ LIB WITH MAIN AND EXTRA ###########
set(svutUnitTestBase_SRCS UnitTestMain.cpp UnitTestExtra.cpp UnitTest_svutException.cpp)
add_library(svutUnitTestBase ${svutUnitTestBase_SRCS}) 


############# BUILD ALL TESTS ##################
set(svutUnitTest_CASES svutCodeLocation svutException svutObjectMethod svutStatusInfo
		svutExTestStatus svutExNotify svutExAssert svutAssert svutTestMethod)
IF (TEST_COVERAGE) ############ HERE THE CASE FOR COVERAGE
	set(svutUnitTest_ALLSRC)
	set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
	foreach(i ${svutUnitTest_CASES})
		list(APPEND svutUnitTest_ALLSRC UnitTest_${i}.cpp)
	endforeach(i)
	add_executable(all_tests ${svutUnitTest_ALLSRC})
	target_link_libraries (all_tests svutUnitTestBase svunittest ${CPPUNIT_LIBRARY})
ELSE (TEST_COVERAGE) ########### HERE THE NORMAL VERSION WITH MULTIPLE EXECUABLE
	#defin test redirection for kdevelop
	foreach(i ${svutUnitTest_CASES})
		add_executable (${i} UnitTest_${i}.cpp)
		target_link_libraries (${i} svutUnitTestBase svunittest ${CPPUNIT_LIBRARY})
		add_test(${i} ${i})
	endforeach(i)
ENDIF (TEST_COVERAGE)
