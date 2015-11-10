#include "KaratsubaMultiplies.h"
#include <iostream>

KaratsubaMultiplies::KaratsubaMultiplies()
{
    //ctor
}

KaratsubaMultiplies::~KaratsubaMultiplies()
{
    //dtor
}

BigInteger KaratsubaMultiplies::Mult(const BigInteger&A, const BigInteger&B){
    int n,k;
    int s1=A.GetSize();
    int s2=B.GetSize();
    if(s1>s2) n=s1; else n=s2;
    k=n>>1;

    if(n<100) return Multiplies::Mult(A,B);

    BigInteger A1 = A, A2 = A>>k;
    A1.Resize(k);
    A1.ClearFirstZeros();

    BigInteger B1 = B, B2 = B>>k;
    B1.Resize(k);
    B1.ClearFirstZeros();

    BigInteger A1B1 = Mult(A1,B1);
    BigInteger A2B2 = Mult(A2,B2);

    BigInteger AB=A1B1+  (( Mult(A1+A2,B1+B2)-(A1B1+A2B2))<<k)  + (A2B2<<2*k);

    AB.ClearFirstZeros();
    return AB;
};
