#include "Multiplies.h"
#include <iostream>

Multiplies::Multiplies()
{
    //ctor
}

Multiplies::~Multiplies()
{
    //dtor
}
BigInteger Multiplies::Mult(const BigInteger &num1, const BigInteger &num2){
    if(num1.GetSystem()!=num2.GetSystem()) throw 2;
    BigInteger integer("0",num1.GetSystem());

    for(int i=0; i<num2.GetSize(); ++i)
    integer=integer + (MultByNum(num1,num2.GetAt(i))<<i);

    return integer;

};

BigInteger Multiplies::MultByNum(const BigInteger &num, int a){
    BigInteger ans("0",num.GetSystem());
    int d=0;
    for(int i=0; d>0 || i<num.GetSize(); ++i){
        ans[i]=num.GetAt(i)*a+d;
        d=ans[i]/num.GetSystem();
        ans[i]%=num.GetSystem();
    }

    //std::cout<<num<<"*"<<a<<"="<<ans<<std::endl;
    return ans;
}
