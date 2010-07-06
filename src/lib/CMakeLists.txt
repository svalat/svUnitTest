#setup svUnitTest library

#group files
set(svUnitTest_SRC svutExTestStatus.cpp svutStatusInfo.cpp svutCodeLocation.cpp svutException.cpp)

set(svUnitTest_INC svutObjectMethodeGenericImpl.h svutObjectMethode.h svutCodeLocation.h 
	svutException.h)

#define targets
add_library (svunittest ${svUnitTest_SRC})
#install
INSTALL(TARGETS svunittest
	ARCHIVE DESTINATION lib)
INSTALL(FILES ${svUnitTest_INC} DESTINATION include/svUnitTest)