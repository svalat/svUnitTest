#setup svUnitTest library

#group files
set(svUnitTest_SRC svutTestFunction.cpp)

set(svUnitTest_INC svutObjectMethodeGenericImpl.h svutObjectMethode.h svutTestFunction.h)

#define targets
add_library (svunittest ${svUnitTest_SRC})
#install
INSTALL(TARGETS svunittest
	ARCHIVE DESTINATION lib)
INSTALL(FILES ${svUnitTest_INC} DESTINATION include/svUnitTest)