#include <iostream>

#include "BigInteger.h"

using namespace std;

int main(){
    vector<int> v;

    v.push_back(2);
    v.push_back(3);

    BigInteger bi(v,10,10);

    for(int i=4; i>=0; --i)
        cout<<bi[i];


}
