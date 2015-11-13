#ifndef DIXONFACTORIZATION_H
#define DIXONFACTORIZATION_H

#include "Factorization.h"


class DixonFactorization : public Factorization
{
    public:
        BigInteger GetFactor(const BigInteger & num);
};

#endif // DIXONFACTORIZATION_H
