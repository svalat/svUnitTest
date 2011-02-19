######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.1.0                        #
#            DATE     : 01/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

To compile the project :

$> mkdir build
$> cd build
$> cmake ..
$> make
$> make install

                    -----------------------

You can change the prefix path for installation with the command : 

$> cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/myprefix

                    -----------------------

By default the test suite will be build if CPPunit is present on your system, to disable it, you
may use :

$> cmake .. -DDISABLE_UNIT_TESTS=yes

                    -----------------------
                    
If you encouter some issues with the test suite and cppunit, you can replace cppunit by a light
implementation with :

$> cmake .. -DDISABLE_CPPUNIT=yes

This is more to pass the test suite on non unix platform like Windows as CPPunit installation is not
friendly.

                    -----------------------

You can run the internal unit test before installing  :

$> make test

                    -----------------------

To geneate test coverage, we need to setup CFLAGS for gcc+gcov :
	-CMAKE_CXX_FLAGS="-O0 -fprofile-arcs -ftest-coverage"
	-CMAKE_C_FLAGS="-O0 -fprofile-arcs -ftest-coverage"
	-CMAKE_EXE_LINKER_FLAGS="-O0 -fprofile-arcs -ftest-coverage

You can do it simply by using :

$> cmake .. -DTEST_COVERAGE=1

Now build, run the tests and call lcov and genhtml :

$> make
$> ./src/test/all_tests
$> lcov -o out.info -c -d .
$> genhtml -o html out.info

                    -----------------------
