#include "KaratsubaMultiplies.h"

KaratsubaMultiplies::KaratsubaMultiplies()
{
    //ctor
}

KaratsubaMultiplies::~KaratsubaMultiplies()
{
    //dtor
}

BigInteger KaratsubaMultiplies::Mult(BigInteger&num1, BigInteger&num2){
    BigInteger ans(0,10);

    int s1=num1.GetSize();
    int s2=num2.GetSize();

    int b_sys = num1.GetSystem();

    int n=1, m=0;

    for(; n<s1 || n<s2; n=n<<1,++m);

    int k=n>>1;

    std::vector<int> v;
    v.assign(k,0);

    for(int i=s1-1; i>=k; --k)
        v[i]=num1[i];

    BigInteger x1(v,b_sys,b_sys);

    for(int i=std::min(s1,k)-1; i>=0; --k)
        v[i]=num1[i];

    BigInteger x2(v,b_sys,b_sys);

    v.assign(k,0);

    for(int i=s2-1; i>=k; --k)
        v[i]=num2[i];

    BigInteger y1(v,b_sys,b_sys);

    for(int i=std::min(s2,k)-1; i>=0; --k)
        v[i]=num2[i];

    BigInteger y2(v,b_sys,b_sys);

    Mult(x1,y1)+( )


    return ans;
};
