//This is the file cmake will look at to generate the test executable,
//please remember to include the individual test files so they get compiled
//as well <3

#include "gtest/gtest.h"

#include "town_tests.cpp"
#include "entity_tests.cpp"
//#include "your_tests_here.cpp"

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
