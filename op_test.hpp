#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "NineOpMock.hpp"
#include "ZeroOpMock.hpp"
#include "NegativeOpMock.hpp"
#include "Add.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_DOUBLE_EQ(test->evaluate(), 8);
}

TEST(OpMockTest, OpEvaluatePos) {
    NineOpMock* test = new NineOpMock();
    EXPECT_DOUBLE_EQ(test->evaluate(), 9.2);
}

TEST(OpMockTest, OpEvaluateZero) {
    ZeroOpMock* test = new ZeroOpMock();
    EXPECT_DOUBLE_EQ(test->evaluate(), 0.0);
}

TEST(NegativeOpMock, OpEvaluateNeg) {
    NegativeOpMock* test = new NegativeOpMock();
    EXPECT_DOUBLE_EQ(test->evaluate(), -9);
}

TEST(AddTest, AddTwoPosNums) {
    Op* val1 = new Op(8);
    Op* val2 = new Op(4);

    Add* test = new Add(val1, val2);
    EXPECT_DOUBLE_EQ(test->evaluate(), 12);
    EXPECT_EQ(test->stringify(), "(8.000000+4.000000)");
}

TEST(AddTest, AddPosNegNum) {
    Op* val1 = new Op(-4.3);
    Op* val2 = new Op(9.7);

    Add* test = new Add(val1, val2);
    EXPECT_DOUBLE_EQ(test->evaluate(), 5.4);
    EXPECT_EQ(test->stringify(), "(-4.300000+9.700000)");
}

TEST(AddTest, AddWithOperationChild) {
    Op* val1 = new Op(3.3);
    Op* val2 = new Op(7.9);
    Op* val3 = new Op(4.6);
    Add* add1 = new Add(val2, val3);

    Add* test = new Add(val1, add1);
    EXPECT_DOUBLE_EQ(test->evaluate(), 15.8);
    EXPECT_EQ(test->stringify(), "(3.300000+(7.900000+4.600000))");
}

#endif //__OP_TEST_HPP__
