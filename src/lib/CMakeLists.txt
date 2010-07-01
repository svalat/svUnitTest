#setup svUnitTest library

#group files
set(svUnitTest_SRC svutCodeLocation.cpp)

set(svUnitTest_INC svutObjectMethodeGenericImpl.h svutObjectMethode.h svutCodeLocation.h)

#define targets
add_library (svunittest ${svUnitTest_SRC})
#install
INSTALL(TARGETS svunittest
	ARCHIVE DESTINATION lib)
INSTALL(FILES ${svUnitTest_INC} DESTINATION include/svUnitTest)