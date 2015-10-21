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
    /*static int lvl =0; ++lvl;
    for(int i=0; i<lvl; ++i) std::cout<<"  ";
    std::cout<<"Mult: "<<A<<" * "<<B<<std::endl;*/
    int s1=A.GetSize();
    int s2=B.GetSize();

    //std::cout << "Mult"<<std::endl;

    int n,m,k;
    for(n=1, m=0; n<s1 || n<s2; n=n<<1,++m); k=n>>1;


    /*if(n==1){
        int ans = A.GetAt(0)*B.GetAt(0);
        BigInteger AB;
        AB[0]=ans%A.GetSystem();
        AB[1]=ans/A.GetSystem();
        //for(int i=0; i<lvl; ++i) std::cout<<"  ";
        //std::cout<<"Return: "<<AB<<std::endl;
        //--lvl;
        AB.ClearFirstZeros();
        return AB;
    }*/

    if(n<100) return Multiplies::Mult(A,B);

    //std::cout<<"k="<<k<<std::endl;
    BigInteger A1 = A, A2 = A>>k;
    A1.Resize(k);

    BigInteger B1 = B, B2 = B>>k;
    B1.Resize(k);

   // std::cout<< "Here"<<std::endl;
    BigInteger A1B1 = Mult(A1,B1);
    BigInteger A2B2 = Mult(A2,B2);

    //for(int i=0; i<lvl; ++i) std::cout<<"  ";
    //std::cout<<"good"<<std::endl;

    BigInteger AB=A1B1+  (( Mult(A1+A2,B1+B2)-(A1B1+A2B2))<<k)  + (A2B2<<n);
    //for(int i=0; i<lvl; ++i) std::cout<<"  ";
    //std::cout<<"Return: "<<AB<<std::endl;
    //--lvl;*/

    AB.ClearFirstZeros();
    return AB;
};
