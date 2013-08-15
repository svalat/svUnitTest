######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.5.0-dev                    #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C 2.1                 #
######################################################

#setup svUnitTest library

#group files
set(svUnitTest_SRC
	runner/svutArgp.cpp
	runner/svutAutoRegister.cpp
	runner/svutRunner.cpp
	runner/svutTestFilterBasic.cpp
	runner/svutDefaultMain.cpp
	runner/svutRunnerConfig.cpp

	core/svutFlatTestCase.cpp
	core/svutException.cpp
	core/svutExAssert.cpp
	core/svutExNotify.cpp
	core/svutCodeLocation.cpp
	core/svutTestMethod.cpp
	core/svutTestCase.cpp
	core/svutAsserter.cpp
	core/svutStatusInfo.cpp
	core/svutExTestStatus.cpp
	
	listeners/svutListenerSummary.cpp
	listeners/svutListenerDirectOutputter.cpp
	listeners/svutListenerMultiplexer.cpp

	formatters/svutResultFormatterHelper.cpp
	formatters/svutResultSummary.cpp
	formatters/svutResultFormatterStdBW.cpp
	formatters/svutResultFormatterStd.cpp
	formatters/svutResultFormatterQtXml.cpp
	formatters/svutResultFormatterJUnitXml.cpp
	formatters/svutResultFormatter.cpp
	formatters/svutResultFormatterXml.cpp
	formatters/svutResultFormatterStdColored.cpp
	formatters/svutResultFormatterBoostXml.cpp)

set(svUnitTest_INC
	svUnitTest.h

	runner/svutArgp.h
	runner/svutAutoRegister.h
	runner/svutRunner.h
	runner/svutTestFilterBasic.h
	runner/svutDefaultMain.h
	runner/svutRunnerConfig.h
	runner/svutTestCaseBuilder.h
	runner/svutTestFilter.h

	core/svutException.h
	core/svutExAssert.h
	core/svutExNotify.h
	core/svutCodeLocation.h
	core/svutTestMethod.h
	core/svutObjectMethod.h
	core/svutExTestStatus.h
	core/svutAsserter.h
	core/svutAssert.h
	core/svutObjectMethodGenericImpl.h
	core/svutStatusInfo.h
	core/svutTestCase.h
	core/svutFlatTestCase.h

	listeners/svutListener.h
	listeners/svutListenerMultiplexer.h
	listeners/svutListenerSummary.h
	listeners/svutListenerDirectOutputter.h

	formatters/svutResultFormatter.h
	formatters/svutResultSummary.h
	formatters/svutResultFormatterQtXml.h
	formatters/svutResultFormatterStdBW.h
	formatters/svutResultFormatterStdColored.h
	formatters/svutResultFormatterStd.h
	formatters/svutResultFormatterXml.h)

#include subdir headers
include_directories(./ ./formatters ./listeners ./runner ./core)

#enable coverage profiling
set(TEST_COVERAGE no CACHE BOOL "Compile svUnitTest library with coverage CFLAGS.")
IF (TEST_COVERAGE)
	set(CMAKE_CXX_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
	set(CMAKE_C_FLAGS "-O0 -fprofile-arcs -ftest-coverage")
	set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
ENDIF (TEST_COVERAGE)

#define targets
#It didn't seems usefull to made it dynamic for such code validation usage
add_library (svunittest STATIC ${svUnitTest_SRC})

#install
INSTALL(TARGETS svunittest
	ARCHIVE DESTINATION lib${LIB_SUFFIX}
	LIBRARY DESTINATION lib${LIB_SUFFIX})
INSTALL(FILES ${svUnitTest_INC} DESTINATION include/svUnitTest)
