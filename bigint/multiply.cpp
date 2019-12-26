/**
   * PAWEENA MANOTIPYA
   * COMPUTER SCIENCE
   * CS23001
   */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {

    std::ifstream in("data1-2.txt");
    bigint left, right;

    while (in >> left && in >> right) {
        std::cout << "Left:  " << left << std::endl;
        std::cout << "Right:  " << right << std::endl;

        bigint result = left * right;
        std::cout << "Result:  " << result << std::endl;
    }
 
    in.close();
    return 0;
}