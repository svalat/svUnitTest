#setup svUnitTest library

#group files
set(svUnitTest_SRC svutTestCase.cpp svutTestMethod.cpp svutAsserter.cpp svutExNotify.cpp svutExAssert.cpp svutExTestStatus.cpp svutStatusInfo.cpp svutCodeLocation.cpp svutException.cpp)

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
