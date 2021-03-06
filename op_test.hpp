#ifndef __OP_TEST_HPP__
#define __OP_TEST_HPP__

#include "gtest/gtest.h"
 
#include "op.hpp"
#include "NineOpMock.hpp"
#include "ZeroOpMock.hpp"
#include "NegativeOpMock.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Add.hpp"
#include "Pow.hpp"
#include "Sub.hpp"

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

TEST(PowTest, TwoPosNums) {
    Op* val1 = new Op(3.2);
    Op* val2 = new Op(2.0);

    Pow* test = new Pow(val1, val2);
    EXPECT_DOUBLE_EQ(test->evaluate(), 10.24);
    EXPECT_EQ(test->stringify(), "(3.200000**2.000000)");
}

TEST(PowTest, NegExponent) {
    Op* val1 = new Op(2.7);
    Op* val2 = new Op(-2.0);
    
    Pow* test = new Pow(val1, val2);
    EXPECT_FLOAT_EQ(test->evaluate(), 0.137174211);
    EXPECT_EQ(test->stringify(), "(2.700000**-2.000000)");
}

TEST(PowTest, PowOp) {
    Op* val1 = new Op(2.0);
    Op* val2 = new Op(2.0);
    Op* val3 = new Op(2.0);
    Pow* pow = new Pow(val2, val3);

    Pow* test = new Pow(val1, pow);
    EXPECT_DOUBLE_EQ(test->evaluate(), 16.0);
    EXPECT_EQ(test->stringify(), "(2.000000**(2.000000**2.000000))");
}

TEST(SubTest, SubTwoPosNums) {
    Op* val1 = new Op(4.3);
    Op* val2 = new Op(3.7);

    Sub* test = new Sub(val1, val2);
    EXPECT_DOUBLE_EQ(test->evaluate(), 0.6);
    EXPECT_EQ(test->stringify(), "(4.300000-3.700000)");
}

TEST(SubTest, FirstNumLarger) {
    Op* val1 = new Op(3.7);
    Op* val2 = new Op(4.3);

    Sub* test = new Sub(val1, val2);
    EXPECT_DOUBLE_EQ(test->evaluate(), -0.6);
    EXPECT_EQ(test->stringify(), "(3.700000-4.300000)");
}

TEST(SubTest, SubOpChild) {
    Op* val1 = new Op(3.79);
    Op* val2 = new Op(1.32);
    Op* val3 = new Op(2.95);
    Sub* sub = new Sub(val2, val3);

    Sub* test = new Sub(val1, sub);
    EXPECT_DOUBLE_EQ(test->evaluate(), 5.42);
    EXPECT_EQ(test->stringify(), "(3.790000-(1.320000-2.950000))");
}

#endif //__OP_TEST_HPP__
