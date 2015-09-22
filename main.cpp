#include <iostream>

#include "BigInteger.h"

using namespace std;

int main(){
    vector<int> v;

    v.push_back(2);
    v.push_back(3);

    BigInteger bi(v,10,10);

    cout<<bi.GetAt(1)<<bi.GetAt(0)<<endl;

}
