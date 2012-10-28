######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 05/2011                      #
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
or
$> ../configure --prefix=/usr/local/myprefix

                    -----------------------

By default the test suite will be build if CPPunit is present on your system, to
disable it, you may use :

$> cmake .. -DDISABLE_UNIT_TESTS=yes
of
$> ../configure --disable-unit-tests

                    -----------------------

If you encouter some issues with the test suite and cppunit, you can replace
cppunit by a light implementation with :

$> cmake .. -DDISABLE_CPPUNIT=yes
of
$> ../configure --disable-cppunit

This is more to pass the test suite on non unix platform like Windows as CPPunit
installation is not friendly.

                    -----------------------

You can run the internal unit test before installing  :

$> make test

                    -----------------------

To geneate test coverage, we need to setup CFLAGS for gcc+gcov :
	-CMAKE_CXX_FLAGS="-O0 -fprofile-arcs -ftest-coverage"
	-CMAKE_C_FLAGS="-O0 -fprofile-arcs -ftest-coverage"
	-CMAKE_EXE_LINKER_FLAGS="-O0 -fprofile-arcs -ftest-coverage

You can do it simply by using :

$> cmake .. -DTEST_COVERAGE=yes
or
$> ../configure --enable-gcc-coverage

Now build, run the tests and call lcov and genhtml :

$> make
$> ./src/test/all_tests
$> lcov -o out.info -c -d .
$> genhtml -o html out.info

                    -----------------------

If you want to develop in the library with KDevelop, you may want to use the
kdev-xtest plugin to get the svUnitTest suite results directly in kdevelop
interface. This can be done by enable the self testing mode. So the svUnitTest
test suite will be build with svUnitTest itself with kdevelop integration
support :

$> cmake .. -DENABLE_SELF_TEST=yes
or
$> ../configure --enable-self-test

                    -----------------------

To validate svUnitTest project in Jenkins, you may be interested by using :

$> cmake .. -DENABLE_DEBUG -DENABLE_SELF_TEST=yes -DENABLE_VALGRIND=yes -DENABLE_JUNIT_OUTPUT=yes
or
$> ../configure --enable-debug --enable-self-test --enable-valgrind --enable-junit-output

It will generates report files while doing "make test" or using ctest :
	- **/*.junit.xml for detailed unit test reports.
	- **/*.memcheck.xml for valgrind reports.
