######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 05/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#project definition
cmake_minimum_required (VERSION 2.6)
project(example_test_string CXX)

#check the presence of svUnitTest
find_package(svUnitTest REQUIRED)

#done optional actions
if ( SVUNITTEST_FOUND )
	#Place here you optional code
endif( SVUNITTEST_FOUND )

#setup directories
include_directories(${SVUNITTEST_INCLUDE_DIR})

#If you need to setup the libdir
#set(LIBS ${LIBS} ${svUnitTest_LIBRARIES})

#Now you can build your tests
add_executable(testString testString.cpp)
target_link_libraries(testString ${SVUNITTEST_LIBRARY})

######################################################
#To auto build multiple test cases with one file per test :

#setup the test list

#set(myProject_CASES test1 test2 test3)

#script to build the rules

#foreach(i ${myProject_CASES})
#	add_executable (${i} ${i}.cpp)
#	target_link_libraries (${i} ${SVUNITTEST_LIBRARY})
#	add_test(${i} ${i})
#endforeach(i)
