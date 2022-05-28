/*************************************************************************
	> File Name: main.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Dec 31 13:59:31 2020
 ************************************************************************/
#include <mxwgoog/test.h>

int add(int a, int b) {
    return a + b;
}

TEST(TESTfunc, add) {
    EXPECT_EQ(add(2, 0), 2);
    EXPECT_NE(add(3, 7), 10);
    EXPECT_EQ(add(2, 5), 6);
    EXPECT_GE(add(2, 8), 9);
}

TEST(TESTfunc, add2) {
    EXPECT_EQ(add(9, 0), 2);
    EXPECT_LT(add(3, 7), 10);
    EXPECT_GT(add(1, 5), 6);
    EXPECT_EQ(add(2, 8), 10);
}

TEST(TEST, funcadd) {
    EXPECT_EQ(add(2, 0), 2);
    EXPECT_LE(add(3, 7), 10);
    EXPECT_EQ(add(2, 5), 7);
    EXPECT_EQ(add(2, 7), 9);
}

int main(){
    return RUN_ALL_TESTS();
}
