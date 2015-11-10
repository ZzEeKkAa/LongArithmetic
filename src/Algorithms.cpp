#include "Algorithms.h"

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
