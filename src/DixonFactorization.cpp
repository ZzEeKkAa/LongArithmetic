#include "DixonFactorization.h"

#include <vector>
#include <cmath>
#include <iostream>

BigInteger DixonFactorization::GetFactor(const BigInteger & num){
    // https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%94%D0%B8%D0%BA%D1%81%D0%BE%D0%BD%D0%B0

    // 1. Factor base
    static int arr_p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,
73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,
179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,
283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,
419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,
547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,
661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,
811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,
947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,
1087,1091,1093,1097,1103};
    static std::vector<BigInteger> p(sizeof(arr_p)/sizeof(int));
    for(int i=0; i<p.size(); ++i){
        p[i]=BigInteger(arr_p[i],num.GetSystem());
    }

    BigInteger sq_num=Algorithms::sqrt(num);
    double lg=(num.GetSize()+0.)/log10(2.71);
    double L=exp(sqrt(lg*log(lg)));

    int M=sqrt(L);
    std::cout<<"M = "<<M<<std::endl;

    int m,l=1,r=p.size()-1,h;
    while(l<r){
        m=(l+r+1)/2;
        if(p[m]>M) r=m-1;
        else       l=m;
    }
    h=l+1;

    std::cout<<"h: "<<h<<std::endl;

    std::vector<std::vector<int> > matrix, bkp;
    std::vector<int> vect;
    std::vector<BigInteger> bs;

    BigInteger a,b,d,t;
    BigInteger zero("0",num.GetSystem());
    b=sq_num;
    do{
        //2. Generating b
        b=Algorithms::Random(sq_num,num);
        //b=b+BigInteger("1",b.GetSystem());
        //std::cout<<"checking "<<b<<std::endl;
        //3. Calculating a
        a=(b*b) % num;
        vect.assign(h,0);

        //4. Checking for smooth
        for(int i=0; i<h; ++i){
            d=a/p[i];
            if(d*p[i]==a){
                a=d;
                ++vect[i];
                --i;
            }
        }
        if(d==zero){
            std::cout<<"Good! // Matrix size: "<<matrix.size()<<" // b="<<b<<std::endl;
            matrix.push_back(vect);
            bs.push_back(b);
        }
    }while(matrix.size()<h); //5. repeating while size of matrix less than h
    std::cout<<"Gauss"<<std::endl;


    for(int i=0; i<vect.size(); ++i){ // rows
        for(int j=0; j<matrix.size(); ++j){ // columns
            std::cout<<matrix[j][i]%2<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    // 6. Gauss
    bkp.assign(matrix.begin(), matrix.end());
    std::vector<int> m_c(vect.size(),-1);   // return main element [row]=column
    std::vector<int> m_r(matrix.size(),-1); // return main element [column]=row
    for(int i=0; i<vect.size(); ++i){ // rows
        for(int j=0; j<matrix.size(); ++j){ // columns
            if(matrix[j][i]%2!=0){
                m_r[j]=i;
                m_c[i]=j;
                for(int i0=0; i0<vect.size(); ++i0) if(i!=i0 && matrix[j][i0]%2!=0)
                    for(int j0=0; j0<matrix.size(); ++j0)
                        matrix[j0][i0]+=matrix[j0][i];
                break;
                /*std::cout<<j<<", "<<i<<std::endl;

                for(int i=0; i<vect.size(); ++i){ // rows
                    for(int j=0; j<matrix.size(); ++j){ // columns
                        std::cout<<matrix[j][i]%2<<" ";
                    }
                    std::cout<<std::endl;
                }

                std::cout<<std::endl;*/
            }
        }
    }

    for(int i=0; i<vect.size(); ++i){ // rows
        for(int j=0; j<matrix.size(); ++j){ // columns
            std::cout<<matrix[j][i]%2<<" ";
        }
        std::cout<<std::endl;
    }


    BigInteger x,y;
    std::vector<int> depended;
    for(int i=0; i<matrix.size(); ++i){
        if(m_r[i]==-1){
            depended.resize(0);
            for(int j=0; j<vect.size(); ++j){
                if(matrix[i][j]%2!=0){
                    depended.push_back(m_c[j]);
                }
            }

            if(depended.size()){
                vect.assign(bkp[i].begin(), bkp[i].end());

                x=bs[i];
                for(auto it=depended.begin(); it<depended.end(); ++it){
                    x=x*bs[*it];
                    for(int i=0; i<vect.size(); ++i)
                        vect[i]+=bkp[*it][i];
                }
                x=x%num;

                y=BigInteger("1",num.GetSystem());
                for(int i=0; i<vect.size(); ++i)
                    for(int j=0; j<vect[i]; ++j)
                        y=y*p[i];
                y=y%num;

                if(x!=y && x!=num-y)
                     Algorithms::gcd(x+y,num);
            }
        }
    }

    return GetFactor(num);
}
