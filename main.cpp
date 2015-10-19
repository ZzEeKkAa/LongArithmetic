#include <iostream>

#include "KaratsubaMultiplies.h"
//#include "Multiplies.h"
#include "BigInteger.h"

using namespace std;

int main(){
    vector<int> v;

    v.push_back(2);
    v.push_back(3);

    BigInteger bi("5673242",10);
    BigInteger bi2("5212121",10);
    BigInteger bi3=bi+bi2;
    cout<<bi<<"+"<<bi2<<"="<<bi3<<endl;

    Multiplies *mult = new KaratsubaMultiplies();

    cout<<mult->Mult(bi,bi2)<<endl;

}
