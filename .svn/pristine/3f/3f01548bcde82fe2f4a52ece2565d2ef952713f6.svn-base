/**
   * PAWEENA MANOTIPYA
   * COMPUTER SCIENCE
   * CS23001
   */


#include "bigint.hpp"

// Milestone 1 ////////////////////////////////////////////////////////////////
// Initialize all big integers to zero
bigint::bigint() 
{
    // Put zero into every index
    for (int i = 0; i < CAPACITY; ++i) {
        integers[i] = 0;
    }
}

// Initialize big integers by integers
bigint::bigint(int number) 
{
    // Put number digit by digit
    for (int i = 0; i < CAPACITY; ++i) {
        if (number > 0) {
            int digit = number % 10;
            integers[i] = digit;
            number = number / 10;
        } else {
            integers[i] = 0;
        }
    }
}

bigint::bigint(const char numbers[]) 
{
    // Count total length of numbers
    int length = 0;
    while(numbers[length] != '\0') {
        ++length;
    }

    // Iterate and put each character from back to front
    int charIndex = length - 1;
    for (int i = 0; i < CAPACITY; i++) {
        if (numbers[charIndex] != '\0') {
            integers[i] = int(numbers[charIndex]) - int('0');
            --charIndex;
        } else {
            integers[i] = 0;
        }
    }
}

// Debug big integers
void bigint::debugPrint(std::ostream& out) const 
{

    int index = CAPACITY;

    do {
        --index;
    } while (index > 0 && integers[index] == 0);
    
    do{
        if (index % 80) {
            out << integers[index];
        } else {
            out << integers[index] << std::endl;
        }
        --index;
    } while (index >= 0);
}

// Overloading extraction operator
std::ostream& operator<< (std::ostream& out, bigint rhs) 
{
    rhs.debugPrint(out);
    return out;
}

// Overloading multiply operator for two big integers
bool bigint::operator==(const bigint& rhs) const 
{
    for (int i = 0; i < CAPACITY; ++i) {
        if (integers[i] != rhs.integers[i]) return false;
    }

    return true;
}

// Milestone 2 ////////////////////////////////////////////////////////////////
// Overloading insertion operator
std::istream& operator>> (std::istream& in, bigint& rhs)
{
    char ch, temp[CAPACITY];
    for (int j = 0; j<CAPACITY; j++){
        temp[j] = 0;
    }
    in >> ch;
    for (int i = 0; i<CAPACITY && ch != ';'; ++i){
        temp[i] = ch;
        in >> ch;
    }
    
    rhs = bigint(temp);
    return in;
}

// Overloading plus operator to plus two big integers
bigint bigint::operator+(const bigint& rhs) const 
{

    int temp = 0;
    int remainder = 0;

    bigint sum;

    for (int i = 0; i < CAPACITY; i++) {
        remainder = integers[i] + rhs.integers[i] + remainder;
        // Get last digits and store it
        temp = remainder % 10;
        sum.integers[i] = temp;

        remainder = remainder / 10;
    }

    return sum;
}

// Get i digits of big integers assume integer is valid number
int bigint::operator[](int i) const 
{
    return integers[i];
}

// Milestone 3 ////////////////////////////////////////////////////////////////
// Multply big integers with digit
bigint bigint::timesDigit(int digit) const {
    
    bigint times;
    int remainder = 0;
    int result = 0;

    for (int i = 0; i < CAPACITY; i++){
        remainder = integers[i] * digit + remainder;
        result = remainder % 10;
        times.integers[i] = result;

        remainder = remainder / 10;
    }
    return times;
}

// Shift big integers and fill zero back to it
bigint bigint::times10(int n) const {

    bigint temp;

    // Shift to the left and assign zero back of it
    for (int i = CAPACITY - 1 - n; i >= 0; --i){
        temp.integers[i + n] = integers[i];
        temp.integers[i] = 0;
    }

    return temp;
}

// Overloading multiply operator
bigint bigint::operator*(const bigint& rhs) const {
    bigint product = 0;
    for (int i = 0; i< CAPACITY; i++){
        product = product + (timesDigit(rhs.integers[i])).times10(i);
    }
    return product;
}