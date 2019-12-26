//  Stack class test program
//
//  Tests: push pop
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
        a.push(1);
        a.push(2);
        a.push(3);
      

        // VERIFY
        assert(a.length() == 3);
    }

    {
         // TEST
         stack<int> a;
         a.push(1);
         a.pop();
         a.push(2);
         a.push(3);

         // VERIFY
         assert(a.length() == 2);
    }

    { 
         // TEST
         stack<int> a;
         stack<int> b;
        
         a.push(2);
         a.push(1);
         a.pop();
         b.push(2);

         assert(a == b);

    }
         

    std::cout << "Done testing push pop." << std::endl;
}
