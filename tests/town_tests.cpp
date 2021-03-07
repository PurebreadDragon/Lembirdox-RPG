#ifndef __TOWN_TESTS__
#define __TOWN_TESTS__

#include "./../Town.hpp"

//Tests begin
TEST(TownTests, DefaultCase) {
   Town* test = new Town();
   EXPECT_EQ(5, 5);
   delete test;
}
//Tests end
#endif
