#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "BigInteger.h"

#include <vector>
#include <complex>

class Algorithms
{
    private:
        static int rev(int num, int lg_n);
    public:
        static BigInteger gcd(BigInteger a, BigInteger b);
        static BigInteger abs(BigInteger const &a);
        static BigInteger Random(BigInteger const &minimal, BigInteger const &maximal);
        static void FastFourierTransform(std::vector<std::complex<long double> > & a, bool invert);
};

#endif // ALGORITHMS_H
