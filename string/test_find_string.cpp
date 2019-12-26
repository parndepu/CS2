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
        String str1("hello world");
        String str2("world");
        
        // Verify
        assert(str1.findstr(0, str2) == 6);
    }

    {
        // Setup
        String str1("hello world");
        String str2("hello");
        
        // Verify
        assert(str1.findstr(6, str2) == -1);
    }

    {
        // Setup
        String str1(" abc ");
        String str2("bc");
        
        // Verify
        assert(str1.findstr(0, str2) == 2);
    }

    {
        // Setup
        String str1("hello world");
        String str2("o w");
        
        // Verify
        assert(str1.findstr(0, str2) == 4);
    }
    
    std::cout << "Done testing find_string" << std::endl;
}