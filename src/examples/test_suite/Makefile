######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.1.0                        #
#            DATE     : 01/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

##################### COMMANDS #######################
CXX=g++
RM=rm -f
PKGCONFIG=pkg-config
####################### FLAGS ########################
SVUNITTEST_PREFIX=/usr
CXXFLAGS=-I${SVUNITTEST_PREFIX}/include
LDFLAGS=-L${SVUNITTEST_PREFIX}/lib -lsvunittest

#################### VARIABLES #######################
TARGETS=testSuite

##################### RULES ##########################
all: ${TARGETS}

testSuite: main.o testString.o testNothing.o
	${CXX} $^ -o $@ ${LDFLAGS}

%.o: %.cpp
	${CXX} -c $< -o $@ ${CXXFLAGS}

clean:
	${RM} *.o
	${RM} ${TARGETS}
