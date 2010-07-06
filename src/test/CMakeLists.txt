include_directories (${svUnitTest_SOURCE_DIR}/src/lib/)

############ LIB WITH MAIN AND EXTRA ###########
set(svutUnitTestBase_SRCS UnitTestMain.cpp UnitTestExtra.cpp UnitTest_svutException.cpp)
add_library(svutUnitTestBase ${svutUnitTestBase_SRCS}) 


############# BUILD ALL TESTS ##################
set(svutUnitTest_CASES svutCodeLocation svutException svutObjectMethode svutStatusInfo
	svutExTestStatus)
#defin test redirection for kdevelop
foreach(i ${svutUnitTest_CASES})
	add_executable (${i} UnitTest_${i}.cpp)
	target_link_libraries (${i} svutUnitTestBase svunittest ${CPPUNIT_LIBRARY})
	add_test(${i} ${i})
endforeach(i)
