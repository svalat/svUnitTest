PREFIX=${PWD}/../../../
CXX=g++
SVUNITTEST_CFLAGS=-I${PREFIX}/include
SVUNITTEST_LDFLAGS=-L${PREFIX}/lib -lsvunittest

ACLOCAL=aclocal
AUTOCONF=autoconf
AUTOMAKE=automake
CD=cd
MKDIR=mkdir
RMDIR=rm -rf
EXPORT=export


targets=build_with_autotools/build/src/testString build_with_cmake/build/testString build_with_makefile/testString build_with_pkg-config/testString std_string/testString_step1 std_string/testString_step2 test_suite/testSuite


all: ${targets}

build_with_autotools/build/Makefile:
	if ! test -d build_with_autotools/build; then ${MKDIR} build_with_autotools/build; fi
	${CD} build_with_autotools && ${ACLOCAL}
	${CD} build_with_autotools && ${AUTOCONF}
	${CD} build_with_autotools && ${AUTOMAKE} --copy --add-missing --foreign
	${CD} build_with_autotools/build && PKG_CONFIG_PATH=${PREFIX}/share/pkgconfig ../configure --with-svUnitTest
	
build_with_autotools/build/src/testString: build_with_autotools/build/Makefile
	${MAKE} -C build_with_autotools/build


build_with_cmake/build/Makefile:
	if ! test -d build_with_cmake/build; then ${MKDIR} build_with_cmake/build; fi
	${CD} build_with_cmake/build/ && cmake .. -DCMAKE_MODULE_PATH=${PREFIX}/share/cmake/Modules

build_with_cmake/build/testString: build_with_cmake/build/Makefile
	${MAKE} -C build_with_cmake/build/

build_with_makefile/testString:
	${MAKE} -C build_with_makefile SVUNITTEST_PREFIX=${PREFIX}

build_with_pkg-config/testString:
	PKG_CONFIG_PATH=${PREFIX}/share/pkgconfig ${MAKE} -C build_with_pkg-config

std_string/testString_step1: std_string/testString_step1.cpp
	${CXX} $< ${SVUNITTEST_CFLAGS} ${SVUNITTEST_LDFLAGS} -Wall -o $@

std_string/testString_step2: std_string/testString_step2.cpp
	${CXX} $< ${SVUNITTEST_CFLAGS} ${SVUNITTEST_LDFLAGS} -Wall -o $@

test_suite/testSuite:
	${MAKE} -C test_suite SVUNITTEST_PREFIX=${PREFIX}

clean:
	${RMDIR} build_with_autotools/build
	${RMDIR} build_with_cmake/build/
	${RM} build_with_makefile/testString
	${RM} build_with_pkg-config/testString
	${RM} std_string/testString_step1 std_string/testString_step2
	${RM} test_suite/testSuite

test:
	build_with_autotools/build/src/testString
	build_with_cmake/build/testString
	build_with_makefile/testString
	build_with_pkg-config/testString
	std_string/testString_step1 && exit 1 || echo ok
	std_string/testString_step2
	test_suite/testSuite && exit 1 || echo ok

.PHONY: ${targets}
