#!/bin/bash

for tmp in dev_dec-events dev_doc-asserts dev_doc-auto_register dev_doc-defaultMain dev_doc-defs dev_doc-directories dev_doc-exceptions dev_doc-filtering dev_doc-formatter \
dev_doc-gcov dev_doc-global_xml dev_doc-location dev_doc-obj_meth dev_doc-runner dev_doc-status_and_asserts dev_doc-style dev_doc-updateVersion  \
user_doc-available_assertions user_doc-build_cmake user_doc-build_makefile user_doc-build_pkg-config user_doc-build_your_first_suite user_doc-extend_macro \
user_doc-extend_type user_doc-html user_doc-install user_doc-status user_doc-test_coverage user_doc-write_first_test 
do
	curl "http://localhost:8080/trac/wiki/${tmp}?format=doxygen" > ${tmp}.dox
done
