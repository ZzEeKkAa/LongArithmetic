#include "Algorithms.h"
#include "BigInteger.h"

#include <cstdlib>
#include <ctime>

#define PI 3.14159265359

int Algorithms::rev (int num, int lg_n) {
	int res = 0;
	for (int i=0; i<lg_n; ++i)
		if (num & (1<<i))
			res |= 1<<(lg_n-1-i);
	return res;
}

void Algorithms::FastFourierTransform(std::vector<std::complex<long double> > & a, bool invert){
    int n = (int) a.size();
	int lg_n = 0;
	while ((1 << lg_n) < n)  ++lg_n;

	for (int i=0; i<n; ++i)
		if (i < rev(i,lg_n))
			std::swap (a[i], a[rev(i,lg_n)]);

	for (int len=2; len<=n; len<<=1) {
		long double ang = 2*PI/len * (invert ? -1 : 1);
		std::complex<long double> wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			std::complex<long double> w (1);
			for (int j=0; j<len/2; ++j) {
				std::complex<long double> u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

BigInteger Algorithms::Random(BigInteger const &minimal, BigInteger const &maximal){
    BigInteger d(maximal-minimal);
    srand(time(NULL));
    BigInteger ans("0",d.GetSystem());
    for(int i=0; i<d.GetSize(); ++i){
        ans[i]=rand()%ans.GetSystem();
    }
    ans[d.GetSize()-1]=ans[d.GetSize()-1]%d[d.GetSize()-1];
    return ans+minimal;
}

#include <iostream>
BigInteger Algorithms::gcd(BigInteger a, BigInteger b){
    //if() return a;
    BigInteger zero("0",a.GetSystem());
    while(a!=zero && b!=zero){
        std::cout<<"iteration "<<a<<" "<<b<<std::endl;
        if(a>b) a=a%b;
        else b=b%a;
    }

    return a+b;
}
BigInteger Algorithms::abs(BigInteger const &a){
    if(a.IsNegative()) return -a;
    return a;
}
