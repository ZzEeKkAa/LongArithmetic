#include "SchonhageMulriplies.h"
#include "Algorithms.h"

SchonhageMulriplies::SchonhageMulriplies()
{
    //ctor

}

SchonhageMulriplies::~SchonhageMulriplies()
{
    //dtor
}

BigInteger SchonhageMulriplies::Mult(const BigInteger&num1, const BigInteger&num2){
    if(num1.GetSystem()!=num2.GetSystem());
    std::vector<std::complex<long double> > a, b;
    a.assign(num1.GetSize(),0);
    for(int i=0; i<num1.GetSize(); ++i) a[i]=num1.GetAt(i);

    b.assign(num2.GetSize(),0);
    for(int i=0; i<num2.GetSize(); ++i) b[i]=num2.GetAt(i);

    int n=std::max(a.size(),b.size());
    int n_st2=1;

    while(n>n_st2) n_st2=n_st2<<1;
    n_st2=n_st2<<1;
    a.resize(n_st2,0);
    b.resize(n_st2,0);


    Algorithms::FastFourierTransform(a,false);
    Algorithms::FastFourierTransform(b,false);
    for(int i=0; i<n_st2; ++i) a[i]*=b[i];
    Algorithms::FastFourierTransform(a,true);

    BigInteger ans("0",num1.GetSystem());


    long long buf=0;
    for(int i=0; i<a.size() || buf>0; ++i){
        ans[i]=(((long long)(a[i].real()+0.5))+buf)%ans.GetSystem();
        buf=(((long long)(a[i].real()+0.5))+buf)/ans.GetSystem();
    }

    ans.ClearFirstZeros();

    return ans;
}
