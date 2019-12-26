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
        String str2("world");
        
        // Verify
        assert(str1 == "hello");
        assert(str2 == "world");

        String result = str1 + str2;
        assert(result == "helloworld");
    }

    {
        // Setup
        String str1(" a");
        String str2("b ");
        
        // Verify
        assert(str1 == " a");
        assert(str2 == "b ");

        String result = str1 + str2;
        assert(result == " ab ");
    }

    {
        // Setup
        String str1("\0");
        String str2("b ");
        
        // Verify
        assert(str1 == "\0");
        assert(str2 == "b ");

        String result = str1 + str2;
        assert(result == "b ");
    }

    {
        // Setup
        String str1(" ");
        String str2("   ");
        String str3("    ");
        
        // Verify
        assert(str1 == " ");
        assert(str2 == "   ");
        assert(str3 == "    ");

        String result = str1 + str2 + str3;
        assert(result == "        ");
    }
    
    std::cout << "Done testing concat" << std::endl;
}