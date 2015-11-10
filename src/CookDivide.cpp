#include "CookDivide.h"

const BigInteger CookDivide::Div(const BigInteger &a, const BigInteger &b){
    int precision=b.GetSize()*4;
    return a*GetInversed(b,precision)>>precision;
}

const BigInteger CookDivide::GetInversed(const BigInteger &b, int precision){
    BigInteger ans("1",b.GetSystem()); ans=ans<<(precision-1);
    BigInteger two("2",b.GetSystem()); two=two<<precision;

    for(int i=0; i<precision; ++i)
        ans=(ans*(two-ans*b))>>precision;

    return ans;
}
