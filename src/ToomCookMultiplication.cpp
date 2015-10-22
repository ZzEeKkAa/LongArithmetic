#include "ToomCookMultiplication.h"

ToomCookMultiplies::ToomCookMultiplies()
{
    //ctor
}

ToomCookMultiplies::~ToomCookMultiplies()
{
    //dtor
}

BigInteger ToomCookMultiplies::Mult(const BigInteger&A, const BigInteger&B){

    int s1=A.GetSize();
    int s2=B.GetSize();

    int n,k;
    //for(n=1, m=0; n<s1 || n<s2; n*=3,++m); k=n/3;
    if(s1>s2) n=s1; else n=s2;
    k=n/3;


    if(n<100) return Multiplies::Mult(A,B);

    BigInteger A1 = A, A2 = A>>k, A3=A>>(2*k);
    A1.Resize(k);
    A1.ClearFirstZeros();
    A2.Resize(k);
    A2.ClearFirstZeros();

    BigInteger B1 = B, B2 = B>>k, B3=B>>(2*k);
    B1.Resize(k);
    B1.ClearFirstZeros();
    B2.Resize(k);
    B2.ClearFirstZeros();

    BigInteger A1B1 = Mult(A1,B1);
    BigInteger A2B2 = Mult(A2,B2);
    BigInteger A3B3 = Mult(A3,B3);

    BigInteger AB=A1B1+  (( Mult(A1+A2,B1+B2)-(A1B1+A2B2))<<k)+  (( Mult(A1+A3,B1+B3)-(A1B1+A3B3)+A2B2)<<2*k) + (( Mult(A2+A3,B2+B3)-(A2B2+A3B3))<<n) + (A3B3<<n+k);

    AB.ClearFirstZeros();
    return AB;
};
