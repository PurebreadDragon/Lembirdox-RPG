#include "gtest/gtest.h"

#include "town_tests.cpp"
#include "entity_tests.cpp"
#include "item_tests.cpp"
#include "room_tests.cpp"

int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
