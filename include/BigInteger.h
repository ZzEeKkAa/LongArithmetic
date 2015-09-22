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
        virtual ~BigInteger();
    protected:
    private:
        bool negative;
        int system;
};

#endif // BIGINTEGER_H
