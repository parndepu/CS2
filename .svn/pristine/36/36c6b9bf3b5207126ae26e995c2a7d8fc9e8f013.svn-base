//  String test program
//
//  Tests:
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
        assert(str1[3] == 'l');
    }

    {
        // Setup
        String str1("\0");
        
        // Verify
        assert(str1[0] == '\0');
    }

    {
        // Setup
        String str1(" x ");
        
        // Verify
        assert(str1[1] == 'x');
    }
    
    std::cout << "Done testing subscript" << std::endl;
}