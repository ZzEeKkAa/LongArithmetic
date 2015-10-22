#include <iostream>
#include <stdio.h>

#include "KaratsubaMultiplies.h"
#include "ToomCookMultiplication.h"
//#include "Multiplies.h"
#include "BigInteger.h"

using namespace std;

int main(){
    //freopen("res.txt","w",stdout);
    vector<int> v;

    v.push_back(2);
    v.push_back(3);

    string s1="12",s2="16";

    s1.assign(100000,'2');
    s2.assign(100000,'1');

    //cout<<s1;

    BigInteger bi (s1,10);
    BigInteger bi2(s2,10);
    //cout<<bi<<endl;
    bi.ConvertTo(10000);
    bi2.ConvertTo(10000);

    //cout<<bi<<endl;

    Multiplies *mult = new ToomCookMultiplies();
    //Multiplies *mult = new KaratsubaMultiplies();
    //Multiplies *mult = new Multiplies();

    bi.SetDefaultMultiplication(mult);

    BigInteger bi3 = bi*bi2;


    //cout<<bi<<"*"<<bi2<<"="<<endl<<endl<<bi3<<endl;/*/**/

}
