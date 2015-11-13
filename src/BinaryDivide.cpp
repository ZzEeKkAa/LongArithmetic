#include "BinaryDivide.h"

BinaryDivide::BinaryDivide()
{
    //ctor
}

BinaryDivide::~BinaryDivide()
{
    //dtor
}

const BigInteger BinaryDivide::Div(const BigInteger &a, const BigInteger &b){
    if(b>a) return BigInteger("0",a.GetSystem());
    if(b==a) return BigInteger("1",a.GetSystem());
    BigInteger l("1",b.GetSystem()),r=a,m;
    BigInteger one("1",b.GetSystem());
    while(l<r){
        m=(l+r+one)/2;
        if(a<m*b)
            r=m-one;
        else
            l=m;
    }

    return l;
}
