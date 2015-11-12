#ifndef DIXONFACTORIZATION_H
#define DIXONFACTORIZATION_H

#include "Factorization.h"


class DixonFactorization : public Factorization
{
    public:
        DixonFactorization();
        virtual ~DixonFactorization();
        BigInteger GetFactor(BigInteger num);
    protected:
    private:
};

#endif // DIXONFACTORIZATION_H
