#include "CookDivide.h"

const BigInteger CookDivide::Div(const BigInteger &a, const BigInteger &b){
    if(a==b) return BigInteger("1",a.GetSystem());
    int precision=b.GetSize(); if(precision<a.GetSize()) precision = a.GetSize(); precision+=10;
    BigInteger ans = a*GetInversed(b,precision)>>precision;
    //while(ans*b<a) ans=ans+BigInteger("1",ans.GetSystem());
    //ans=ans-BigInteger("1",ans.GetSystem());
    return ans;
}

const BigInteger CookDivide::GetInversed(const BigInteger &b, int precision){
    BigInteger ans("1",b.GetSystem()); ans=ans<<(precision-b.GetSize()+1);
    BigInteger two("2",b.GetSystem()); two=two<<precision+1;
    BigInteger five("0",b.GetSystem()); five[0]=b.GetSystem()/2; five=five<<precision;

    int iter = precision*2;
    for(int i=0; i<iter; ++i){
        ans=(ans*(two-ans*b)+five)>>precision+1;
    }

    five=five>>precision;

    return ans+five>>1;
}
