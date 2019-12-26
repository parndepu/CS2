//  Stack class test program
//
//  Tests: copy constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> a;
        a.push(1);
        a.push(2);
        a.push(3);       

        stack<int> b(a);
        a.pop();

        // VERIFY
        assert(a.length() == 2);
        assert(b.length() == 3);
    }
    
    {
        // TEST
        stack<int> a;
        stack<int> b(a);
        
        // VERIFY
        assert(a == b);
    }
    
    std::cout << "Done testing copy constructor." << std::endl;

}
