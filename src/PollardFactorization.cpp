#include "PollardFactorization.h"

#include <iostream>

PollardFactorization::PollardFactorization()
{
    //ctor
}

PollardFactorization::~PollardFactorization()
{
    //dtor
}


BigInteger PollardFactorization::GetFactor(const BigInteger &num){
    const int MAX_ITERATIONS = 100;
    BigInteger one("1",num.GetSystem());
    BigInteger x = Algorithms::Random(one,num);
    //std::cout<<"rand: "<<x<<std::endl;
    BigInteger y = one,g;
    for(int i = 0, stage = 2; i<MAX_ITERATIONS; ++i){
        std::cout<<i<<std::endl;
        g = Algorithms::gcd(num, Algorithms::abs(x-y));
        if(g>one && g<num) return g;
        if (i == stage ){
            y = x;
            stage = stage<<1;
        }
        x = (x*x + one)%num;
    }

    //std::cout<<(one-one!=BigInteger("0",one.GetSystem()))<<std::endl;
    //return one;
    return Algorithms::gcd(num, Algorithms::abs(x-y));
}
