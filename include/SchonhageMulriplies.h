#ifndef SCHONHAGEMULRIPLIES_H
#define SCHONHAGEMULRIPLIES_H

#include "Multiplies.h"


class SchonhageMulriplies : public Multiplies
{
    public:
        SchonhageMulriplies();
        virtual ~SchonhageMulriplies();
        BigInteger Mult(const BigInteger&num1, const BigInteger&num2);
    protected:
    private:
};

#endif // SCHONHAGEMULRIPLIES_H
