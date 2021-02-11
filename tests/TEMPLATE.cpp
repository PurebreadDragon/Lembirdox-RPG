//In case you need it, this is the base template for a test cpp file:

#ifndef __TESTFILENAME__
#define __TESTFILENAME__

//Tests begin
TEST(TestSuiteName, TestName) {
    int* test = new int(5);
    EXPECT_EQ(test, 5);
    delete test;
}
//Tests end

#endif
