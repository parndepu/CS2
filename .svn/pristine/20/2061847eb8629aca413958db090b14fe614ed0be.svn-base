//  Stack class test program
//
//  Tests: swap
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        stack<int> a;
        stack<int> b;

        a.push(1);
        a.push(2); 
        a.push(3); 

        a.swap(b);
      
        // VERIFY
        assert(a.length() == 0);
        assert(b.length() == 3);
        assert(a != b);
    }

    std::cout << "Done testing swap." << std::endl;
}
