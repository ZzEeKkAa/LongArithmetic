#include "PollardFactorization.h"

PollardFactorization::PollardFactorization()
{
    //ctor
}

PollardFactorization::~PollardFactorization()
{
    //dtor
}


BigInteger PollardFactorization::GetFactor(const BigInteger &num){
    const int MAX_ITERATIONS = 10000;
    BigInteger x = Algorithms::random(1, num-BigInteger("2",num.GetSystem()));
    BigInteger one("1",num.GetSystem());
    BigInteger y = one,g;
    for(int i = 0, stage = 2; i<MAX_ITERATIONS; ++i){
        g = Algorithms::gcd(num, Algorithms::abs(x-y));
        if(g>one && g<num) return g;
        if (i == stage ){
            y = x;
            stage = stage<<1;
        }
        x = (x*x + one)%num;
    }
    return Algorithms::gcd(num, Algorithms::abs(x-y));
}
