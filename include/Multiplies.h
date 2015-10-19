#ifndef MULTIPLIES_H
#define MULTIPLIES_H

class Multiplies;

#include "BigInteger.h"

class Multiplies
{
    public:
        Multiplies();
        virtual ~Multiplies();
        virtual BigInteger Mult(BigInteger &num1, BigInteger &num2);
    protected:
    private:
};

#endif // MULTIPLIES_H
