//  Stack class test program
//
//  Tests: destructor
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

        // VERIFY
        assert(a.length() == 0);
        assert(a == stack<int>());
    }

    std::cout << "Done testing destructor." << std::endl;

}
