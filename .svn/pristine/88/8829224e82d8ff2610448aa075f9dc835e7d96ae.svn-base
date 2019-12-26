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
        String str1("a");
        String str2("b");
        
        // Verify
        assert(str1 < str2);
    }

    {
        // Setup
        String str1("abcc");
        String str2("abcd");
        
        // Verify
        assert(str1 < str2);
    }

    {
        // Setup
        String str1(" c");
        String str2(" c b");
        
        // Verify
        assert(str1 < str2);
    }

    {
        // Setup
        String str1("adb");
        String str2("cdb");
        
        // Verify
        assert(str1 < str2);
    }

    {
        // Setup
        String str1("aaaabaaaa");
        String str2("aaaacaaaa");
        
        // Verify
        assert(str1 < str2);
    }
    
    std::cout << "Done testing lessThan" << std::endl;
}