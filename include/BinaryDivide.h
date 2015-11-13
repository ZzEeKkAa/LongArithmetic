#ifndef BINARYDIVIDE_H
#define BINARYDIVIDE_H

#include "Divide.h"


class BinaryDivide : public Divide
{
    public:
        BinaryDivide();
        virtual ~BinaryDivide();
        const BigInteger Div(const BigInteger &a, const BigInteger &b);
    protected:
    private:
};

#endif // BINARYDIVIDE_H
