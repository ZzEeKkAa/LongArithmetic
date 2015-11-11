#ifndef POLLARDFACTORIZATION_H
#define POLLARDFACTORIZATION_H

#include "Factorization.h"


class PollardFactorization : public Factorization
{
    public:
        PollardFactorization();
        virtual ~PollardFactorization();
        BigInteger GetFactor(const BigInteger &num);
    protected:
    private:
};

#endif // POLLARDFACTORIZATION_H
