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
        bi = bi.times10(5);

        // Verify
        assert(bi == 300000);
    }
    
    //Add test cases as needed.
    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi(30);

        // Test 
        bi = bi.times10(5);

        // Verify
        assert(bi == 3000000);
    }

    {
        //------------------------------------------------------
        // Setup fixture
        bigint bi("0300");

        // Test 
        bi = bi.times10(5);

        // Verify
        assert(bi == 30000000);
    }

    std::cout << "Done testing times_10" << std::endl;
}

