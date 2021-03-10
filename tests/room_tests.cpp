#ifndef __ROOM_TESTS__
#define __ROOM_TESTS__

#include "./../Room.hpp"
#include "./../Factory.hpp"
#include "./../Warrior.cpp"

#include "gtest/gtest.h"

RoomFactory rFactory;

//----- Room tests begin -----
//Check if all constructors and destructors are working properly
TEST(RoomSuite, ConstructDestructAllRooms) {
    Room* test = nullptr;
    for (unsigned i = 1; i <= NUM_ODDITY_ROOMS; ++i) {
        test = rFactory.generate(i + 30000);
        ASSERT_TRUE(test != nullptr);
        EXPECT_TRUE(test->getName() != "");
        delete test;
        test = nullptr;
    }
    for (unsigned i = 1; i <= NUM_AMBIENT_ROOMS; ++i) {
        test = rFactory.generate(i + 35000);
        ASSERT_TRUE(test != nullptr);
        EXPECT_TRUE(test->getName() != "");
        delete test;
        test = nullptr;
    }
}

//Check if exits can be added and received properly
TEST(RoomSuite, RoomsCanExit) {
    Room* test1 = nullptr;
    Room* test2 = nullptr;
    for (unsigned i = 1; i + 1 <= NUM_ODDITY_ROOMS; ++i) {
        test1 = rFactory.generate(i + 30000);
        test2 = rFactory.generate(i + 30001);
        test1->addExit(test2);
        test1->getExitLabels();
        EXPECT_TRUE(test1->getExit(1).getName() != "");
        delete test1;
        delete test2;
    }
    for (unsigned i = 1; i + 1 <= NUM_AMBIENT_ROOMS; ++i) {
        test1 = rFactory.generate(i + 35000);
        test2 = rFactory.generate(i + 35001);
        test1->addExit(test2);
        test1->getExitLabels();
        EXPECT_TRUE(test1->getExit(1).getName() != "");
        delete test1;
        delete test2;
    }
}
#endif
