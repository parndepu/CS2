//  String test program
//
//  Tests: length capacity
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        // Setup
        String str1("hello");

        // Verify
        assert(str1.capacity() == 5);
    }

    {
        // Setup
        String str1("hello ");
        
        // Verify
        assert(str1.capacity() == 6);
    }

    {
        // Setup
        String str1("hello world");
        
        // Verify
        assert(str1.capacity() == 11);
    }
    
    std::cout << "Done testing len_cap" << std::endl;
}