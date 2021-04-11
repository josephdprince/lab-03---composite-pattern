#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"
 
#include "op.hpp"
#include "NineOpMock.hpp"
#include "ZeroOpMock.hpp"
#include "NegativeOpMock.hpp"
#include "Mult.hpp"
#include "Div.hpp"

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

TEST(MultTest, MultEvaluateNonZero) {
    Op* val1 = new Op(2);
    Op* val2 = new Op(3);
    Mult* test = new Mult(val1, val2);
    EXPECT_DOUBLE_EQ(test->evaluate(), 6);
    EXPECT_EQ(test->stringify(), "(2.000000*3.000000)");
}

TEST(MultTestNeg, MultEvaluatePosNeg) {
    Op* val1 = new Op(-5.7);
    Op* val2 = new Op(3.2);
    Mult* test = new Mult(val1, val2);
    EXPECT_FLOAT_EQ(test->evaluate(), -18.24);
    EXPECT_EQ(test->stringify(), "(-5.700000*3.200000)");
}

TEST(MultTestOp, MultEvaluateOpInput) {
    Op* val1 = new Op(-4);
    Op* val2 = new Op(6);
    Mult* op1 = new Mult(val1, val2);
    Op* val3 = new Op(2.0);
    Mult* op2 = new Mult(op1, val3);
    EXPECT_FLOAT_EQ(op2->evaluate(), -48);
}

TEST(DivTest, DivEvaluateNonZero) {
    Op* val1 = new Op(6);
    Op* val2 = new Op(3);
    Div* test = new Div(val1, val2);
    EXPECT_DOUBLE_EQ(test->evaluate(), 2);
    EXPECT_EQ(test->stringify(), "(6.000000/3.000000)");
}

TEST(DivTestNeg, DivEvaluatePosNeg) {
    Op* val1 = new Op(-24.2);
    Op* val2 = new Op(2.0);
    Div* test = new Div(val1, val2);
    EXPECT_FLOAT_EQ(test->evaluate(), -12.1);
    EXPECT_EQ(test->stringify(), "(-24.200000/2.000000)");
}

TEST(DivTestOp, DivEvaluateOpInput) {
    Op* val1 = new Op(-24);
    Op* val2 = new Op(6);
    Div* op1 = new Div(val1, val2);
    Op* val3 = new Op(2.0);
    Div* op2 = new Div(op1, val3);
    EXPECT_FLOAT_EQ(op2->evaluate(), -2);
}

#endif //__OP_TEST_HPP__
