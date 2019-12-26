//  Stack class test program
//
//  Tests: overloading assign operator
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
        stack<int>  a;
        a.push(1); a.push(2); a.push(3);
        
        stack<int> b;
        b = a;

        // VERIFY
        assert(b.length() == 3);
    }


    {
        // TEST
        stack<int> a;
        stack<int> b;
        stack<int> c;
        
        a = b = c;
        
        // VERIFY
        assert(a == c);
    }
    
    std::cout << "Done testing assign." << std::endl;

}
