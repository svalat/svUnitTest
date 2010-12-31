#setup svUnitTest library

#group files
set(svUnitTest_SRC svutDefaultMain.cpp svutTestFilterBasic.cpp svutAutoRegister.cpp svutRunner.cpp svutRunnerConfig.cpp svutResultFormatterStdColored.cpp svutResultSummary.cpp svutAsserter.cpp
	svutResultFormatterStd.cpp svutResultFormatterStdBW.cpp svutListenerDirectOutputter.cpp
	svutListenerSummary.cpp svutListenerMultiplexer.cpp svutException.cpp svutTestCase.cpp
	svutTestMethod.cpp  svutExNotify.cpp svutExAssert.cpp svutExTestStatus.cpp svutStatusInfo.cpp
	svutCodeLocation.cpp)

set(svUnitTest_INC svutObjectMethodGenericImpl.h svutObjectMethod.h svutCodeLocation.h 
	svutException.h)

#enable coverage profiling
IF (TEST_COVERAGE)
	set(CMAKE_CXX_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
	set(CMAKE_C_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
	set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
ENDIF (TEST_COVERAGE)

#define targets
add_library (svunittest ${svUnitTest_SRC})
#install
INSTALL(TARGETS svunittest
	ARCHIVE DESTINATION lib)
INSTALL(FILES ${svUnitTest_INC} DESTINATION include/svUnitTest)
