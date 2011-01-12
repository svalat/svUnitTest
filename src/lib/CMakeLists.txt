#setup svUnitTest library

#group files
set(svUnitTest_SRC svutResultFormatterQtXml.cpp svutResultFormatter.cpp svutResultFormatterXml.cpp
	svutDefaultMain.cpp svutTestFilterBasic.cpp svutAutoRegister.cpp svutRunner.cpp
	svutRunnerConfig.cpp svutResultFormatterStdColored.cpp svutResultSummary.cpp svutAsserter.cpp
	svutResultFormatterStd.cpp svutResultFormatterStdBW.cpp svutListenerDirectOutputter.cpp
	svutListenerSummary.cpp svutListenerMultiplexer.cpp svutException.cpp svutTestCase.cpp
	svutTestMethod.cpp  svutExNotify.cpp svutExAssert.cpp svutExTestStatus.cpp svutStatusInfo.cpp
	svutCodeLocation.cpp)

set(svUnitTest_INC svutAsserter.h svutAssert.h svutAutoRegister.h svutCodeLocation.h
	svutDefaultMain.h svutExAssert.h svutException.h svutExNotify.h svutExTestStatus.h
	svutListenerDirectOutputter.h svutListener.h svutListenerMultiplexer.h svutListenerSummary.h
	svutObjectMethodGenericImpl.h svutObjectMethod.h svutResultFormatter.h
	svutResultFormatterQtXml.h svutResultFormatterStdBW.h svutResultFormatterStdColored.h
	svutResultFormatterStd.h svutResultFormatterXml.h svutResultSummary.h svutRunnerConfig.h
	svutRunner.h svutStatusInfo.h svutTestCaseBuilder.h svutTestCase.h svutTestFilterBasic.h
	svutTestFilter.h svutTestMethod.h)

#enable coverage profiling
IF (TEST_COVERAGE)
	set(CMAKE_CXX_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
	set(CMAKE_C_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
	set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
ENDIF (TEST_COVERAGE)

#define targets
add_library (svunittest SHARED ${svUnitTest_SRC})
#install
INSTALL(TARGETS svunittest
	LIBRARY DESTINATION lib)
INSTALL(FILES ${svUnitTest_INC} DESTINATION include/svUnitTest)
