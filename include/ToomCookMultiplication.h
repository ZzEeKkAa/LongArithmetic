#ifndef TOOMCOOKMULTIPLICATION_H
#define TOOMCOOKMULTIPLICATION_H

#include "Multiplies.h"


class ToomCookMultiplies : public Multiplies
{
    public:
        ToomCookMultiplies();
        virtual ~ToomCookMultiplies();
        BigInteger Mult(const BigInteger&num1, const BigInteger&num2);
    protected:
    private:
};

#endif // TOOMCOOKMULTIPLICATION_H
