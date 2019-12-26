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
        String str1('\0');
        String str2("");
        
        // Verify
        assert(str1 == '\0');
        assert(str2 == "");
        assert(str1 == str2);
    }

    {
        // Setup
        String str1('x');
        String str2("x");
        
        // Verify
        assert(str1 == "x");
        assert(str2 == 'x');
        assert(str1 == str2);
    }

    {
        // Setup
        String str1("x ");
        String str2(" x");
        
        // Verify
        assert(str1 == "x ");
        assert(str2 == " x");
        assert(!(str1 == str2));
    }

    {
        // Setup
        String str1("hello");
        String str2("olleh");
        
        // Verify
        assert(str1 == "hello");
        assert(str2 == "olleh");
        assert(!(str1 == str2));
    }

    {
        // Setup
        String str1(" x ");
        String str2(" y ");
        
        // Verify
        assert(str1 == " x ");
        assert(str2 == " y ");
        assert(!(str1 == str2));
    }
    
    std::cout << "Done testing equal" << std::endl;
}