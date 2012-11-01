######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.4.0                        #
#            DATE     : 11/2012                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#subdirs
add_subdirectory (lib)
add_subdirectory (integration)
add_subdirectory (examples)
add_subdirectory (resources)
add_subdirectory(extra-tools)
if (NOT DISABLE_UNIT_TESTS)
	add_subdirectory (tests)
endif(NOT DISABLE_UNIT_TESTS)
