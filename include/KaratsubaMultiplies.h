#ifndef KARATSUBAMULTIPLIES_H
#define KARATSUBAMULTIPLIES_H

#include <Multiplies.h>


class KaratsubaMultiplies : public Multiplies
{
    public:
        KaratsubaMultiplies();
        virtual ~KaratsubaMultiplies();
        BigInteger Mult(const BigInteger&num1, const BigInteger&num2);
    protected:
    private:
};

#endif // KARATSUBAMULTIPLIES_H
