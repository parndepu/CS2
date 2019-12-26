#include "stack.hpp"
#include <cassert>
#include <iostream>

int  main()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int> a;
        stack<double> b;
        stack<bool> c;
      
        // VERIFY
        assert(a == stack<int>());
        assert(b == stack<double>());
        assert(c == stack<bool>());
    }

    {
        // TEST
        stack<int> a;
        stack<int> b;
        
        // VERIFY
        assert(a == b);
    }

    {
        // TEST
        stack<int> a;
        
        // VERIFY
        assert(a.length() == 0);
    }
    
    std::cout << "Done testing default constructor." << std::endl;   
}
