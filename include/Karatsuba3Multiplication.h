#ifndef KARATSUBA3MULTIPLICATION_H
#define KARATSUBA3MULTIPLICATION_H

#include "Multiplies.h"


class Karatsuba3Multiplication : public Multiplies
{
    public:
        Karatsuba3Multiplication();
        virtual ~Karatsuba3Multiplication();
        BigInteger Mult(const BigInteger&num1, const BigInteger&num2);
    protected:
    private:
};

#endif // KARATSUBA3MULTIPLICATION_H
