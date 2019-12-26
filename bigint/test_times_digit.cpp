// bigint Test Program
//
// Tests:  times_10, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(3);

        // Test 
        bi = bi.timesDigit(1);

        // Verify
        assert(bi == 3);  //Will FAIL, fix and add test cases.
    }


    //Add test cases as needed.
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(20);

        // Test 
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == 100);  //Will FAIL, fix and add test cases.
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(22);

        // Test 
        bi = bi.timesDigit(2);

        // Verify
        assert(bi == 44);  //Will FAIL, fix and add test cases.
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("00000009");

        // Test 
        bi = bi.timesDigit(5);

        // Verify
        assert(bi == 45);  //Will FAIL, fix and add test cases.
    }

    
    std::cout << "Done testing bigint * digit" << std::endl;
}

