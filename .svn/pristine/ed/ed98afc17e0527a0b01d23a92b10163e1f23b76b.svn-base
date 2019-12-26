// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);
        assert(digit == 4);
    }
    
    //Add test cases!!

    {
        // Setup
        bigint bi(2);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 2);
        assert(digit == 2);
    }

    {
        // Setup
        bigint bi(10);

        // 0 digit is zero
        int digit = bi[0];

        // Verify
        assert(bi    == 10);
        assert(digit == 0);
    }

    {
        // Setup
        bigint bi("20002");

        // 0 digit is zero
        int digit = bi[0];

        // Verify
        assert(bi    == 20002);
        assert(digit == 2);
    }

    std::cout << "Done testing subscript." << std::endl;
}

