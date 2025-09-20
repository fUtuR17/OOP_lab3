# CMake generated Testfile for 
# Source directory: /workspaces/OOP/lab1
# Build directory: /workspaces/OOP/lab1/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(lab1_tests "/workspaces/OOP/lab1/build/lab1_tests")
set_tests_properties(lab1_tests PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/OOP/lab1/CMakeLists.txt;35;add_test;/workspaces/OOP/lab1/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
