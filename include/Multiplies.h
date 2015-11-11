#ifndef MULTIPLIES_H
#define MULTIPLIES_H

class Multiplies;

#include "BigInteger.h"

class Multiplies
{
    public:
        Multiplies();
        virtual ~Multiplies();
        virtual BigInteger Mult(const BigInteger &num1, const BigInteger &num2);
    protected:
        BigInteger MultByNum(const BigInteger &num, int a);
    private:
};

#endif // MULTIPLIES_H
