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

    std::ifstream in("data1-1.txt");

    bigint left, right;

    while (in >> left && in >> right) {
        // Print left and right
        std::cout << "left:  " << left;
        std::cout << "right:  " << right;

        // Compute result
        bigint result = left + right;
        std::cout << "result:  " << result << std::endl;
    }
 
    in.close();
    return 0;
}
