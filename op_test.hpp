#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"

#include "op.hpp"
#include "NegativeOpMock.hpp"

TEST(OpTest, OpEvaluateNonZero) {
    Op* test = new Op(8);
    EXPECT_EQ(test->evaluate(), 8);
}

TEST(NegativeOpMock, OpEvaluateNeg) {
    NegativeOpMock* test = new NegativeOpMock(-9);
    EXPECT_EQ(test->evaluate(), -9);
}

#endif //__OP_TEST_HPP__
