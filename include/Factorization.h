#ifndef FACTORIZATION_H
#define FACTORIZATION_H

#include "BigInteger.h"
#include "Algorithms.h"

class Factorization
{
    public:
        Factorization();
        virtual ~Factorization();
        virtual BigInteger GetFactor(const BigInteger &num)=0;
    protected:
    private:
};

#endif // FACTORIZATION_H
