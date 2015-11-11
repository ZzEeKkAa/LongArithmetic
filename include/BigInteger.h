#ifndef BIGINTEGER_H
#define BIGINTEGER_H

class BigInteger;

#include <vector>
#include <string>
#include <ostream>
#include "Multiplies.h"

/** @brief This is a class of long numbers.
 * @author Yevhenii Havrylko
 * @date 10.10.2015
 * @version 1.2
 *
 * This class has a simple function: to make work with long numbers easier
 *
 */
class BigInteger
{
    public:
        /** \brief Constructor
         *
         * \param num String number
         * \param system System for number in string
         *
         * Creates new BigInteger object which holds array of digits in the same system as input string
         *
         */
        BigInteger(const BigInteger& num);
        BigInteger(std::string& num, int system=10);
        BigInteger(const char* num="0", int system=10);

        /** \brief Converts to new system
         *
         * \param system The new system in which operations will be done
         *
         */
        void ConvertTo(int system);
        /// @return Current system
        int GetSystem() const;
        /// @return Number length
        int GetSize() const;
        /** @brief Changing length of number
         *
         * @param len New length of number
         * @param defaultValue Values for new digits. By default 0
         *
         */
        void Resize(int len, int defaultValue=0);
        bool IsNegative() const;
        static void SetDefaultMultiplication(Multiplies* multiplies);
        friend const BigInteger operator-(const BigInteger& i);
        friend const BigInteger operator*(const BigInteger& left, const BigInteger& right);
        friend const BigInteger operator/(const BigInteger& left, const BigInteger& right);
        friend const BigInteger operator%(const BigInteger& left, const BigInteger& right);
        friend const BigInteger operator+(const BigInteger& left, const BigInteger& right);
        friend const BigInteger operator-(const BigInteger& left, const BigInteger& right);
        friend bool operator>(const BigInteger& left, const BigInteger& right);
        friend bool operator<(const BigInteger& left, const BigInteger& right);
        friend bool operator==(const BigInteger& left, const BigInteger& right);
        friend bool operator!=(const BigInteger& left, const BigInteger& right);
        BigInteger& operator=(const BigInteger& newInteger);
        const BigInteger operator<<(int bits) const;
        const BigInteger operator>>(int bits) const;
        friend std::ostream &operator<<(std::ostream&out, const BigInteger& integer);
        int &operator[](const int pos);
        int GetAt(int pos) const;
        virtual ~BigInteger();
        void ClearFirstZeros();
    protected:
    private:
        std::vector<int> num;
        int system;
        bool negative;
        static Multiplies* multiplies;
};

#endif // BIGINTEGER_H
