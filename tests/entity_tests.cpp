#ifndef __ENTITY_TESTS__
#define __ENTITY_TESTS__

#include "gtest/gtest.h"

#include "./../Factory.hpp"
#include "./../Entity.hpp"

EnemyFactory factory;
unsigned NUM_ENEMIES = 5; //just update this number as new enemies are introduced.

//----- EnemySuite tests begin -----
//Check if constructors, destructors are working properly
TEST(EnemySuite, ConstructDestructAllEnemies) {
    Enemy* test = nullptr;
    for (unsigned i = 1; i <= NUM_ENEMIES; ++i) {
        test = factory.generate(10000 + i);
        ASSERT_TRUE(test != nullptr); //if any enemy fails to construct, tests will abort.
        EXPECT_NE(test->getName(), ""); //If there's an error in the constructor, this segfaults.
        test->inspect(); //Tests all attributes of an enemy simultaneously.
        delete test; //If there's a fault in the deconstructor, expect trouble here.
    }
}

//Check if enemies can take their turn properly
TEST(EnemySuite, AllEnemiesTakeTurn) {
    Enemy* test = nullptr;
    Entity* dummy = new TEST_DUMMY();
    for (unsigned i = 1; i <= NUM_ENEMIES; ++i) {
        test = factory.generate(10000 + i);
        test->turn(dummy);
        delete test;
    }
    delete dummy;
}

//Check if enemies can take damage properly, and do not heal above maximum HP
TEST(EnemySuite, AllEnemiesPerish) {
    Enemy* test = nullptr;
    for (unsigned i = 1; i <= NUM_ENEMIES; ++i) {
        test = factory.generate(10000 + i);
        test->dealPDamage(99999999); //WE SMITE THEE
        EXPECT_TRUE (!test->isAlive());
        test->heal(999999999); //just kidding we heal thee
        EXPECT_EQ (test->getCurrentHealth(), test->getMaxHealth());
        test->dealMDamage(99999999); //WE SMITE THEE
        EXPECT_TRUE (!test->isAlive());
    }
}
//----- EnemySuite tests complete -----

#endif
