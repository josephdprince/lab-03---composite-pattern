#ifndef __NEGATIVE_OP_MOCK__
#define __NEGATVIE_OP_MOCK__

#include "base.hpp"

class NegativeOpMock : public Base {
    public:
        NegativeOpMock() : Base() { }
        virtual double evaluate() { return -9; }
        virtual std::string stringify() { return "-9"; }
};

#endif //__NEGATIVE_OP_MOCK__
