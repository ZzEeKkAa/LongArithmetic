#include "ToomCookMultiplication.h"


ToomCookMultiplies::ToomCookMultiplies()
{
    //ctor
}

ToomCookMultiplies::~ToomCookMultiplies()
{
    //dtor
}

BigInteger ToomCookMultiplies::DivByNum(const BigInteger &num, int n){
    BigInteger ans=(num);
    int buf=0;
    for(int i=ans.GetSize()-1; i>=0; --i){
        buf*=ans.GetSystem();
        buf+=ans[i];
        ans[i]=buf/n;
        buf%=n;
    }
    ans.ClearFirstZeros();
    return ans;
}


BigInteger ToomCookMultiplies::Mult(const BigInteger&A, const BigInteger&B){

    int s1=A.GetSize();
    int s2=B.GetSize();

    int n,k;
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

    BigInteger p0, p1, pm1, pm2, pi;
    p0=A1;
    p1=A1+A3;
    pm1=p1-A2;
    p1=p1+A2;
    pm2=MultByNum(pm1+A3,2)-A1;
    pi=A3;

    BigInteger q0, q1, qm1, qm2, qi;
    q0=B1;
    q1=B1+B3;
    qm1=q1-B2;
    q1=q1+B2;
    qm2=MultByNum(qm1+B3,2)-B1;
    qi=B3;

    BigInteger r0, r1, rm1, rm2, ri;
    r0 =Mult(p0 ,q0);
    r1 =Mult(p1 ,q1);
    rm1=Mult(pm1,qm1);
    rm2=Mult(pm2,qm2);
    ri =Mult(pi ,qi);

    BigInteger r_0, r_1, r_2, r_3, r_4;
    r_0=r0;
    r_4=ri;
    r_3=DivByNum(rm2-r1,3);
    r_1=DivByNum(r1-rm1,2);
    r_2=rm1-r0;
    r_3=DivByNum(r_2-r_3,2)+MultByNum(ri,2);
    r_2=r_2+r_1-r_4;
    r_1=r_1-r_3;


    BigInteger AB=r_0+(r_1<<k)+(r_2<<2*k)+(r_3<<3*k)+(r_4<<4*k);

    AB.ClearFirstZeros();
    return AB;
};
