//  Stack class test program
//
//  Tests: empty
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
      
        // VERIFY
        assert(a.empty());
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        
        // TEST
        stack<int> a;
        
        a.push(1); 
        a.push(2); 
        a.push(3);
        a.pop();
        a.pop();
        a.pop();
      
        // VERIFY
        assert(a.empty());
    }      

    std::cout << "Done testing empty." << std::endl;
}
