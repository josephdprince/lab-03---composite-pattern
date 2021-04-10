#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "NineOpMock.hpp"
#include "ZeroOpMock.hpp"
#include "NegativeOpMock.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(OpMockTest, OpEvaluatePos) {
    NineOpMock* test = new NineOpMock();
    EXPECT_EQ(test->evaluate(), 9.2);
}

TEST(OpMockTest, OpEvaluateZero) {
    ZeroOpMock* test = new ZeroOpMock();
    EXPECT_EQ(test->evaluate(), 0.0);
}

TEST(NegativeOpMock, OpEvaluateNeg) {
    NegativeOpMock* test = new NegativeOpMock();
    EXPECT_EQ(test->evaluate(), -9);
}

#endif //__OP_TEST_HPP__
