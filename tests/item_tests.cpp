#ifndef __ITEM_TESTS__
#define __ITEM_TESTS__

#include "./../Item.hpp"
#include "./../Factory.hpp"
#include "./../Entity.hpp"
#include "./../Warrior.cpp"

#include "gtest/gtest.h"

ItemFactory iFactory;

//----- ItemSuite tests begin -----
//Check if constructors and destructors working properly
TEST(ItemSuite, ConstructDestructAllItems) {
    Item* test = nullptr;
    for (unsigned i = 1; i <= NUM_ITEMS; ++i) {
        test = iFactory.generate(i + 20000);
        ASSERT_TRUE(test != nullptr); //if any item fails to construct, tests will abandon.
        EXPECT_TRUE(test->getName() != ""); //if there's an error in the constructor, this segfaults.
        test->inspect(); //Tests all attributes simultaneously. Segfaults if an error occurs.
        delete test;
        test = nullptr;
    }
}

//Check if all items can perform ability properly
TEST(ItemSuite, AllItemsAbility) {
    Adventurer* user = new Warrior("Test Warrior","Just a test warrior");
    Entity* target = new TEST_DUMMY();
    Item* test = nullptr;
    int userHealth;
    int targetHealth;
    for (unsigned i = 1; i <= NUM_ITEMS; ++i) {
        user->setHealth(1);
        userHealth = user->getCurrentHealth();
        targetHealth = target->getCurrentHealth();
        test = iFactory.generate(i + 20000);
        test->ability(user, target);
        if (i >= 4 && i <= 7) { //healing potions will aid user's HP
            EXPECT_NE(userHealth, user->getCurrentHealth());
        }
        else if (i >= 10 && i <= 12) { //Cat's Paws need special treatment.
            EXPECT_TRUE(test->getName() != "");
        }
        else if (i == 13) { //Mirror's Edge needs special treatment.
            std::cout << "\nTESTING: PRESS 1, THEN 2.\n";
            test->ability(user, target);
            EXPECT_NE(targetHealth, target->getCurrentHealth());
            test->ability(user, target);
            EXPECT_NE(userHealth, user->getCurrentHealth());
        }
	
        else if (i == 14) { //DebuffStick needs special treatment.
            EXPECT_TRUE(test->getName() != "");
        }
	
	else if (i == 15) { //FakePotion needs special treatment. 
		EXPECT_TRUE(test->getName() != "");
	}
	else if (i == 16) { //FobWatch needs special treatment.
		EXPECT_TRUE(test->getName() != ""); 
	}
 	 
        else {
            EXPECT_NE(targetHealth, target->getCurrentHealth());
        }
        delete test;
    }
    delete user;
    delete target;
}

//Check if all items can be added to an inventory
TEST(ItemSuite, InventoryAllItems) {
    Adventurer* testPlayer = new Warrior("Test Warrior","Just a test warrior");
    Item* test = nullptr;
    int prevInvSize = 0;
    for (unsigned i = 1; i <= NUM_ITEMS; ++i) {
        prevInvSize = testPlayer->getInvSize();
        test = iFactory.generate(i + 20000);
        testPlayer->addItem(test);
        EXPECT_TRUE(testPlayer->getInvSize() != prevInvSize);
        //do not delete test, deleting the player does that automatically.
    }
    delete testPlayer;
}
//----- ItemSuite tests end -----
#endif
