#include "range.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(rangeTest, testContainsElement) {
    Range r(5, 10);
    EXPECT_TRUE(r.containsElement(6));
    EXPECT_FALSE(r.containsElement(15));
}

TEST(rangeTest, testContainsRange) {
    Range a(1, 10);
    Range b(2, 5);
    Range c(20, 30);
    EXPECT_TRUE(a.containsRange(b));
    EXPECT_FALSE(b.containsRange(a));
    EXPECT_FALSE(c.containsRange(a));
    EXPECT_FALSE(c.containsRange(b));
}

TEST(rangeTest, testIsLessThan) {
    Range a(3, 20);
    Range b(10);
    Range c(0);
    EXPECT_TRUE(a.isLessThan(b));
    EXPECT_TRUE(a.isLessThan(c));
    EXPECT_FALSE(b.isLessThan(a));
    EXPECT_FALSE(c.isLessThan(a));
}

TEST(rangeTest, testIsGreaterThan) {
    Range a(4, 10);
    Range b(20);
    Range c(30);
    EXPECT_TRUE(b.isGreaterThan(a));
    EXPECT_FALSE(a.isGreaterThan(b));
    EXPECT_FALSE(b.isGreaterThan(c));
}

TEST(rangeTest, testIsEqual) {
    Range a(2, 7);
    Range b(2, 7);
    Range c(3, 2);
    EXPECT_TRUE(a.isEqual(b));
    EXPECT_TRUE(b.isEqual(a));
    EXPECT_FALSE(a.isEqual(c));
    EXPECT_FALSE(c.isEqual(b));
}

TEST(rangeTest, testIsDisjoint) {
    Range a(3, 7);
    Range b(5, 7);
    Range c(8, 10);
    EXPECT_TRUE(a.isDisjoint(c));
    EXPECT_TRUE(b.isDisjoint(c));
    EXPECT_FALSE(a.isDisjoint(b));
}

TEST(rangeTest, testIsOverlapping) {
    Range a(3, 7);
    Range b(5, 7);
    Range c(8, 10);
    EXPECT_FALSE(a.isOverlapping(c));
    EXPECT_FALSE(b.isOverlapping(c));
    EXPECT_TRUE(a.isOverlapping(b));
}

TEST(rangeTest, testPrintRange) {
    Range a(3);
    Range b(5, 2);
    EXPECT_TRUE(a.printRange() == "0, 1, 2, 3, ");
    EXPECT_TRUE(b.printRange() == "2, 3, 4, 5, ");
    EXPECT_FALSE(a.printRange() == "5, 7");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}