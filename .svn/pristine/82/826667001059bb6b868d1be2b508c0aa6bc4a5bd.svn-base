// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }

    //Add test cases as needed.
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(12000005);
      bigint right(0000005);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 12000005);
      assert(right  == 5);
      assert(result == 12000010);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(0000005);
      bigint right(12000005);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 0000005);
      assert(right  == 12000005);
      assert(result == 12000010);
    }
    
    
    std::cout << "Done with testing addition." << std::endl;
}

