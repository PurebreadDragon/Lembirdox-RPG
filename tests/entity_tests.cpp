#ifndef __ENTITY_TESTS__
#define __ENTITY_TESTS__

#include "gtest/gtest.h"

#include "./../Factory.hpp"
#include "./../Entity.hpp"
#include "./../Adventurer.cpp"
#include "./../Warrior.cpp"
#include "./../Wizard.cpp"
#include "./../Samurai.cpp"

EnemyFactory factory;
unsigned NUM_ENEMIES = 5; //update these numbers when new things are introduced.
unsigned NUM_CLASSES = 3;


//----- EnemySuite tests begin -----
//Check if constructors, destructors are working properly
TEST(EnemySuite, ConstructDestructAllEnemies) {
    Enemy* test = nullptr;
    for (unsigned i = 1; i <= NUM_ENEMIES; ++i) {
        test = factory.generate(10000 + i);
        ASSERT_TRUE(test != nullptr); //If any enemy fails to construct, tests will abort.
        EXPECT_NE(test->getName(), ""); //If there's an error in the constructor, this segfaults.
        test->inspect(); //Tests all attributes of an enemy simultaneously. SegFaults if an error occurs.
        delete test;
    }
}

//Check if enemies can take their turn properly
TEST(EnemySuite, AllEnemiesTakeTurn) {
    Enemy* test = nullptr;
    Entity* dummy = new TEST_DUMMY();
    int priorHP;
    for (unsigned i = 1; i <= NUM_ENEMIES; ++i) {
        priorHP = dummy->getCurrentHealth();
        test = factory.generate(10000 + i);
        test->turn(dummy); //this should give output for every attack.
        if (i == 4) { test->turn(dummy); } //ShieldSkeleton needs special treatment.
        EXPECT_TRUE(dummy->getCurrentHealth() != priorHP); //expect damage to be done to dummy.
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
        delete test;
    }
}
//----- EnemySuite tests complete -----



//----- AdventurerSuite tests begin -----
//Check if constructor, destructors are working properly
TEST(AdventurerSuite, ConstructDestructAdventurers) {
    Adventurer* test = nullptr;
    for (unsigned i = 1; i <= NUM_CLASSES; ++i) {
        switch (i) {
        case 1:
            test = new Warrior("TestWarrior","Just a test warrior");
            break;
        case 2:
            test = new Wizard("TestWizard","Just a test wizard");
            break;
        case 3:
            test = new Samurai("TestSammy","Just a test sammy");
            break;
        }
        ASSERT_TRUE(test != nullptr); //If any class fails to construct, tests will abort.
        test->inspect(); //Tests all attributes of an adventurer simultaneously. SegFaults if an error occurs.
        delete test;
    }
}

//Check if adventurer-unique behaviors are working properly
TEST(AdventurerSuite, AdventurerBehaviors) {
    Adventurer* test = nullptr;
    for (unsigned i = 1; i <= NUM_CLASSES; ++i) {
        switch (i) {
        case 1:
            test = new Warrior("TestWarrior","Just a test warrior");
            break;
        case 2:
            test = new Wizard("TestWizard","Just a test wizard");
            break;
        case 3:
            test = new Samurai("TestSammy","Just a test sammy");
            break;
        }
        EXPECT_EQ(test->getLevel(), 1); //all classes should start at level 1
        test->addExp(50);
        test->addGold(100);
        EXPECT_EQ(test->getGold(), 100);
        EXPECT_EQ(test->getLevel(), 1); //exp 50, required 82.5
        test->deathPenalty();
        EXPECT_EQ(test->getGold(), 50);
        EXPECT_EQ(test->getLevel(), 1); //exp 25, required 82.5
        test->levelUp();
        EXPECT_EQ(test->getLevel(), 2);
        delete test;
    }
}
//----- AdventureSuite tests complete -----

#endif
