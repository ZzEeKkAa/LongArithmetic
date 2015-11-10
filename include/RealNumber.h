#ifndef REALNUMBER_H
#define REALNUMBER_H

#include "BigInteger.h"


class RealNumber : public BigInteger
{
    public:
        RealNumber(const BigInteger& num);
        RealNumber(std::string& num, int system=10);
        RealNumber(const char* num="0", int system=10);
        virtual ~RealNumber();
        RealNumber(const RealNumber& other);
        int GetPrecision();
        int SetPrecision();
        friend const RealNumber operator-(const RealNumber& i);
        friend const RealNumber operator*(const RealNumber& left, const RealNumber& right);
        friend const RealNumber operator+(const RealNumber& left, const RealNumber& right);
        friend const RealNumber operator-(const RealNumber& left, const RealNumber& right);
        friend bool operator>(const BigInteger& left, const BigInteger& right);
        friend bool operator<(const BigInteger& left, const BigInteger& right);
    protected:
    private:
        int precision;
};

#endif // REALNUMBER_H
