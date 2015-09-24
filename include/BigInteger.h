#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <vector>


class BigInteger : private std::vector<int>
{
    public:
        BigInteger(int dec_num, int system);
        BigInteger(char*num, int base_system, int system);
        BigInteger(const std::vector<int>& num, int base_system, int system);
        void ConvertTo(int system);
        int GetSystem();
        int GetAt(int pos);
        int GetSize();
        void Resize(int len, int basic_value=0);
        virtual ~BigInteger();
        friend const BigInteger operator+(const BigInteger& left, const BigInteger& right);
        int &operator[](const int pos);
    protected:
    private:
        bool negative;
        int system;
};

#endif // BIGINTEGER_H
