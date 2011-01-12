#subdirs
add_subdirectory (lib)
add_subdirectory (test)
install(DIRECTORY xslt_html DESTINATION ${CMAKE_INSTALL_PREFIX}/shared/svUnitTest)