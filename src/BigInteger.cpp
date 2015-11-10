#include "BigInteger.h"
#include <iostream>
#include <algorithm>

BigInteger::BigInteger(const BigInteger& integer){
    //ctor
    num.assign(integer.num.begin(),integer.num.end());
    system=integer.system;
    negative=integer.negative;
}

BigInteger::BigInteger(std::string &snum, int system){
    //ctor
    num.assign(snum.size(),0);
    if(system<1) throw 1;

    int i=0;

    negative=false;
    if(snum[0]=='-') { negative=true; ++i; }

    for(; i<num.size(); ++i){
        if(snum[i]>='A' && snum[i]<='Z') num[num.size()-i-1]=snum[i]-'A'+10; else
        if(snum[i]>='0' && snum[i]<='9') num[num.size()-i-1]=snum[i]-'0'; else
        throw 1;
    }
    if(negative) num.resize(num.size()-1);

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
    if(this->system==10 && system==10000){
        this->system=system;
        int d=0;
        for(int i=0; i<num.size(); ++i){
            d*=10; d+=num[i];
            if(i%4==3){
                num[i/4]=d;
                d=0;
            }
        }
        if(d!=0) num[(num.size()-1)/4]=d;
        num.resize( (num.size()-1)/4+1 );
    }
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
    return integer;
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

    BigInteger integer("0",left.GetSystem());

    int d=0;
    if(!left.IsNegative()){
        if(left<right){
            //std::cout<<"HERE"<<std::endl;
            integer=-integer;
            for(int i=0; i<right.GetSize(); ++i){
                integer[i]=d+right.GetAt(i)-left.GetAt(i);
                if(integer[i]<0) { integer[i]+=integer.GetSystem(); d=-1;}
                else d=0;
            }
        }
        else {
            for(int i=0; i<left.GetSize(); ++i){
                integer[i]=d+left.GetAt(i)-right.GetAt(i);
                if(integer[i]<0) { integer[i]+=integer.GetSystem(); d=-1;}
                else d=0;
            }
        }
    } else {
        if(left>right){
            for(int i=0; i<right.GetSize(); ++i){
                integer[i]=d+right.GetAt(i)-left.GetAt(i);
                if(integer[i]<0) { integer[i]+=integer.GetSystem(); d=-1;}
                else d=0;
            }
        }
        else {
            integer=-integer;
            for(int i=0; i<left.GetSize(); ++i){
                integer[i]=d+left.GetAt(i)-right.GetAt(i);
                if(integer[i]<0) { integer[i]+=integer.GetSystem(); d=-1;}
                else d=0;
            }
        }
    }

    integer.ClearFirstZeros();
    return integer;
}

int &BigInteger::operator[](const int pos){
    if(pos<0) throw 1;
    if(pos>=num.size())
        num.resize(pos+1,0);
    return num[pos];
}

bool operator>(const BigInteger& left, const BigInteger& right){
    if(right.IsNegative() && !left.IsNegative())
        return true;
    if(!right.IsNegative() && left.IsNegative())
        return false;
    else{
        //std::cout<<"HERE"<<std::endl;
        int s=left.GetSize(); if(s<right.GetSize()) s=right.GetSize();
        while(s>=0 && left.GetAt(s)==right.GetAt(s)) --s;
        if(s==-1) return false;
        if(left.IsNegative())
            return left.GetAt(s)<right.GetAt(s);
        else
            return left.GetAt(s)>right.GetAt(s);
    }
}

bool operator<(const BigInteger& left, const BigInteger& right){
    return right>left;
}

int BigInteger::GetAt(int pos) const{
    if(pos>=num.size()) return 0;
    return num[pos];
}

std::ostream&operator<<(std::ostream&out, const BigInteger& integer){
    if(integer.negative) out<<'-';
    for(int i=integer.num.size()-1; i>=0; --i)
        out<<integer.num[i];
    return out;
}

const BigInteger BigInteger::operator<<(int bits) const{
    BigInteger integer("0",system);
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
    integer.num.resize(std::max<int>(0,num.size()-bits));
    return integer;
}

Multiplies *BigInteger::multiplies=NULL;
void BigInteger::SetDefaultMultiplication(Multiplies* multiplies){
    BigInteger::multiplies = multiplies;
}
const BigInteger operator*(const BigInteger& left, const BigInteger& right){
    return left.multiplies->Mult(left,right);
}

void BigInteger::ClearFirstZeros(){
    int size=num.size()-1;

    for(; size>0 && num[size]==0; --size); ++size;
    num.resize(size);
}
