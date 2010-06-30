set(svutUnitTest_SRCS main.cpp BasicTest.cpp)

add_executable(svutUnitTest ${svutUnitTest_SRCS})
target_link_libraries (svutUnitTest ${CPPUNIT_LIBRARY})

add_test(svutUnitTest ${EXECUTABLE_OUTPUT_PATH}/svutUnitTest)
