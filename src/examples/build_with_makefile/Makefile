######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0-dev                    #
#            DATE     : 03/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

##################### COMMANDS #######################
CXX=g++
RM=rm -f
PKGCONFIG=pkg-config
####################### FLAGS ########################
ifeq "$SVUNITTEST_PREFIX" ""
SVUNITTEST_PREFIX=/usr
endif
CXXFLAGS=-I${SVUNITTEST_PREFIX}/include
LDFLAGS=-L${SVUNITTEST_PREFIX}/lib -lsvunittest

#################### VARIABLES #######################
TARGETS=testString

##################### RULES ##########################
all: ${TARGETS}

testString: testString.o
	${CXX} $< -o $@ ${LDFLAGS}

%.o: %.cpp
	${CXX} -c $< -o $@ ${CXXFLAGS}

clean:
	${RM} *.o
	${RM} ${TARGETS}
