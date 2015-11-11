#include <iostream>
#include <stdio.h>

#include "KaratsubaMultiplies.h"
#include "ToomCookMultiplication.h"
#include "SchonhageMulriplies.h"
//#include "Multiplies.h"
#include "BigInteger.h"
#include "CookDivide.h"
#include "PollardFactorization.h"

using namespace std;

int main(){
    //freopen("res.txt","w",stdout);
    vector<int> v;

    v.push_back(2);
    v.push_back(3);

    string s1="12",s2="16";

    s1.assign(20,'3');
    s2.assign(20,'1');

    //cout<<s1;

    BigInteger bi (s1,10);
    BigInteger bi2(s2,10);
    //BigInteger a("22435245647",10), b("33651",10);
    BigInteger a("22435245647",10), b("33659",10);
    //cout<<bi<<endl;
    //bi.ConvertTo(1000);
    //bi2.ConvertTo(1000);

    //cout<<bi<<endl;

    CookDivide *divide = new CookDivide();
    //Multiplies *mult = new ToomCookMultiplies();
    //Multiplies *mult1 = new KaratsubaMultiplies();
    //Multiplies *mult = new Multiplies();
    Multiplies *mult = new SchonhageMulriplies();

    //BigInteger::SetDefaultMultiplication(mult);
    BigInteger::SetDefaultMultiplication(mult);

    //cout<<divide->Div(a,b)<<endl;

    BigInteger bi3 = bi*bi2;

    Factorization *fact = new PollardFactorization();

    cout<<fact->GetFactor(bi3)<<"|"<<bi3<<endl;




    //BigInteger::SetDefaultMultiplication(mult1);
    //cout<<bi3-bi*bi2;

    //cout<<bi*bi2-bi3<<endl;

    //cout<<"First:  "<<(bi*bi2)<<endl;
    //cout<<"Second: "<<(bi2*bi)<<endl;

    //cout<<"D: "<<(bi2*bi)-(bi*bi2)<<endl;

    //cout<<bi<<"*"<<bi2<<"="<<endl<<endl<<bi3<<endl;/*/**/

}
