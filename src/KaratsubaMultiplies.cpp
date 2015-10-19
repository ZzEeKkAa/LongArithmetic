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

BigInteger KaratsubaMultiplies::Mult(BigInteger&A, BigInteger&B){
    int s1=A.GetSize();
    int s2=B.GetSize();

    int n,m,k;
    for(n=1, m=0; n<s1 || n<s2; n=n<<1,++m); k=n>>1;

    if(n==1){
        int ans = A[0]*B[0];
        BigInteger AB;
        AB[0]=ans%A.GetSystem();
        int second = ans/A.GetSystem();
        if(second) AB[1]=second;
        return AB;
    }

    BigInteger A1 = A, A2 = A>>k;
    A1.Resize(k);

    BigInteger B1 = B, B2 = B>>k;
    B1.Resize(k);

    BigInteger A1B1 = Mult(A1,B1);
    BigInteger A2B2 = Mult(A2,B2);

    BigInteger AB=A1B1+  (((A1+A2)*(B1+B2)-(A1B1+A2B2))<<k)  + (A2B2<<n);

    return AB;
};
