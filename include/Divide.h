#ifndef DIVIDE_H
#define DIVIDE_H

#include "BigInteger.h"

class Divide
{
    public:
        Divide();
        virtual ~Divide();
        virtual const BigInteger Div(const BigInteger &a, const BigInteger &b)=0;
    protected:
    private:
};

#endif // DIVIDE_H
