######################################################
#            PROJECT  : svUnitTest                   #
#            VERSION  : 0.3.0                        #
#            DATE     : 05/2011                      #
#            AUTHOR   : Valat Sébastien              #
#            LICENSE  : CeCILL-C                     #
######################################################

#subdirs
add_subdirectory (lib)
add_subdirectory (integration)
add_subdirectory (examples)
add_subdirectory (resources)
if (NOT DISABLE_UNIT_TESTS)
	add_subdirectory (tests)
endif(NOT DISABLE_UNIT_TESTS)
