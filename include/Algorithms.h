#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <complex>

class Algorithms
{
    private:
        static int rev(int num, int lg_n);
    public:
        static void FastFourierTransform(std::vector<std::complex<long double> > & a, bool invert);
};

#endif // ALGORITHMS_H
