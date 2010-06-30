set(svutUnitTest_SRCS main.cpp BasicTest.cpp UnitTest_svutObjectMethode.cpp)

include_directories (${svUnitTest_SOURCE_DIR}/src/lib/)

add_executable(svutUnitTest ${svutUnitTest_SRCS})
target_link_libraries (svutUnitTest ${CPPUNIT_LIBRARY})

add_test(svutUnitTest ${EXECUTABLE_OUTPUT_PATH}/svutUnitTest)
