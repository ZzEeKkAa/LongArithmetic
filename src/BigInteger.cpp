#include "BigInteger.h"
#include <iostream>

BigInteger::BigInteger(const BigInteger& integer){
    //ctor
    nll=new int;
    num.assign(integer.num.begin(),integer.num.end());
    system=integer.system;
    negative=integer.negative;
}

BigInteger::BigInteger(std::string &snum, int system){
    //ctor
    nll=new int;
    num.assign(snum.size(),0);
    if(system<1) throw 1;
    for(int i=0; i<num.size(); ++i){
        if(snum[i]>='A' && snum[i]<='Z') num[num.size()-i-1]=snum[i]-'A'+10; else
        if(snum[i]>='0' && snum[i]<='9') num[num.size()-i-1]=snum[i]-'0'; else
        throw 1;
    }

    for(int i=0; i<num.size(); ++i)
        if(num[i]>=system)
            throw 1;
    this->system=system;
}

BigInteger::BigInteger(const char * snum, int system):BigInteger(*new std::string(snum), system){}


BigInteger::~BigInteger()
{
    //dtor
}

void BigInteger::ConvertTo(int system){

}

int BigInteger::GetSystem() const{
    return system;
}

int BigInteger::GetSize() const{
    return num.size();
}

void BigInteger::Resize(int len, int basic_value){
    num.resize(len,basic_value);
}
bool BigInteger::IsNegative() const{
    return negative;
}

BigInteger& BigInteger::operator=(const BigInteger& newInteger){
    num=newInteger.num;
    system = newInteger.system;
    negative=newInteger.negative;
    return *this;
}

const BigInteger operator-(const BigInteger& i){
    BigInteger integer(i);
    if(integer.IsNegative())
        integer.negative=false;
    else
        integer.negative=true;
}


const BigInteger operator+(const BigInteger& left, const BigInteger& right){
    if(left.GetSystem()!=right.GetSystem()) throw 2;
    if(left.IsNegative() && !right.IsNegative()){
        return(right-(-left));
    } else
    if(!left.IsNegative() && right.IsNegative()){
        return(left-(-right));
    }

    BigInteger integer(left);

    for(int i=0,st=0; i<right.GetSize() || st>0; ++i){
        integer[i]+=right.GetAt(i)+st;
        st=integer[i]/integer.GetSystem();
        if(st) integer[i]%=integer.GetSystem();
    }

    return integer;
}


const BigInteger operator-(const BigInteger& left, const BigInteger& right){
    if(left.GetSystem()!=right.GetSystem()) throw 2;

    if(!left.IsNegative() && right.IsNegative() || left.IsNegative() && !right.IsNegative()){
        return(left+(-right));
    }

    BigInteger integer;

    /*
    for(int i=0,st=0; i<right.GetSize() || st>0; ++i){
        integer[i]+=right.GetAt(i)+st;
        st=integer[i]/integer.GetSystem();
        if(st) integer[i]%=integer.GetSystem();
    }*/

    return integer;
}

int &BigInteger::operator[](const int pos){
    if(pos<0) throw 1;
    if(pos>=num.size())
        num.resize(pos+1,0);
    return num[pos];
}

friend bool operator>(const BigInteger& left, const BigInteger& right){
    if(right.IsNegative() && !left.IsNegative())
        return true;
    if(!right.IsNegative() && !left.IsNegative()){
        if(left.GetSize()>right.GetSize()) return true;
        if(left.GetSize()==right.GetSize() && left[left.GetSize()-1]>right[right]
    }
}

friend bool operator<(const BigInteger& left, const BigInteger& right){
    return right>left;
}

int BigInteger::GetAt(int pos) const{
    if(pos>=num.size()) return 0;
    return num[pos];
}

std::ostream&operator<<(std::ostream&out, const BigInteger& integer){
    for(int i=integer.num.size()-1; i>=0; --i)
        out<<integer.num[i];
    return out;
}

const BigInteger BigInteger::operator<<(int bits) const{
    BigInteger integer;
    integer.num.assign(num.size()+bits,0);
    for(int i=0; i<num.size(); ++i){
        integer.num[i+bits]=num[i];
    }
    return integer;
}

const BigInteger BigInteger::operator>>(int bits) const{
    BigInteger integer(*this);
    for(int i=bits; i<num.size(); ++i){
        integer.num[i-bits]=num[i];
    }
    integer.num.resize(num.size()-bits);
    return integer;
}

