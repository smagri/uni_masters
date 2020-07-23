# CMake generated Testfile for 
# Source directory: /lu1/smagri/uni/subj/pms/gtest-building/example
# Build directory: /lu1/smagri/uni/subj/pms/gtest-building/example
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(that-test-I-made "/lu1/smagri/uni/subj/pms/gtest-building/example/runUnitTests")
add_test(that-other-test-I-made "runUnitTests")
subdirs(lib/gtest-1.6.0)
