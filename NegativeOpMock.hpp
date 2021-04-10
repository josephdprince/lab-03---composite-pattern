#ifndef __NEGATIVE_OP_MOCK__
#define __NEGATVIE_OP_MOCK__

#include "base.hpp"

class NegativeOpMock : public Base {
    private:
	double negValue;
    public:
        NegativeOpMock(double value) : Base() { negValue = value; }
        virtual double evaluate() { return negValue; }
        virtual std::string stringify() { return std::to_string(negValue); }
};

#endif //__NEGATIVE_OP_MOCK__
