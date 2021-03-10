#ifndef __TOWN_TESTS__
#define __TOWN_TESTS__

#include "./../Town.hpp"
#include "./../Quest.cpp"
#include "./../Warrior.cpp"

/* Since RoamTown() relies on player input, any number of combinations could be possible.
 * Remember that both functions return nullptr if final input is 0 and a Quest pointer if final input is 4.
 * Disable TownInputs if we're going to demo, otherwise tests may take awhile lol
 */


//----- Town tests begin -----
//Check if constructors and destructors are working properly
TEST(TownSuite, ConstructDestructTown) {
    Town* test = new Town();
    EXPECT_TRUE(test != nullptr);
    delete test;
}

//No expects are possible, needs player input.
TEST(TownSuite, /*DISABLED_*/TownInputs) {
    Adventurer* testPlayer = new Warrior("Test Warrior","Just a test warrior");
    testPlayer->setHealth(50);
    testPlayer->addGold(10000);
    Town* test = new Town();
    Quest* testQuest = test->RoamTown(testPlayer);
    delete testPlayer;
    delete testQuest;
    delete test;
}
//----- Town tests end
#endif
