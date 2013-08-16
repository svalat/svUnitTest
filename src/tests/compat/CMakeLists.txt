######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.5.0-dev                    #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C 2.1                 #
######################################################

######################################################
add_executable(UnitTest_svutGTest UnitTest_svutGTest.cpp)
target_link_libraries (UnitTest_svutGTest svutUnitTestBase svunittest)