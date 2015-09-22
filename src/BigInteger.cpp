#include "BigInteger.h"

BigInteger::BigInteger(int dec_num, int system)
{
    //ctor
}

BigInteger::BigInteger(char*num, int base_system, int system)
{
    //ctor
}

BigInteger::BigInteger(const std::vector<int>&num, int base_system, int system)
{
    //ctor
    if(base_system==system){
        this->assign(num.begin(),num.end());
    }

}

BigInteger::~BigInteger()
{
    //dtor
}

void BigInteger::ConvertTo(int system)
{

}

int BigInteger::GetSystem()
{

}

int BigInteger::GetAt(int pos)
{
    return (*this)[pos];
}
