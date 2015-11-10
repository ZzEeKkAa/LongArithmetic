#ifndef COOKDIVIDE_H
#define COOKDIVIDE_H

#include "BigInteger.h"

class CookDivide
{
    public:
        const BigInteger Div(const BigInteger &a, const BigInteger &b);
    protected:
    private:
        const BigInteger GetInversed(const BigInteger &a, int precision);
};

#endif // COOKDIVIDE_H
