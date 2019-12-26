/**
   * PAWEENA MANOTIPYA
   * COMPUTER SCIENCE
   * CS23001
   */


#ifndef BIGINT_HPP
#define BIGINT_HPP

#include<iostream>

const int CAPACITY = 400;

class bigint {

public:

    // Milestone 1
    bigint();
    bigint(int);
    bigint(const char[]);
    void debugPrint(std::ostream&) const;
    friend std::ostream& operator<< (std::ostream&, bigint);
    bool operator==(const bigint&) const;

    // Milestone 2
    friend std::istream& operator>> (std::istream&, bigint&);
    bigint operator+(const bigint&) const;
    int operator[](int) const;

    // Milestone 3
    bigint timesDigit(int) const;
    bigint times10(int) const; 
    bigint operator*(const bigint&) const;

private:
    int integers[CAPACITY];
};

#endif // BIGINT_HPP