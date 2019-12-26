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
        String str2("world");
        String str3("world");

        str1.swap(str3);
        // Verify
        assert(str1 == str2);
    }

    {
        // Setup
        String str1("hello");
        String str2("world");
        String str3("world");

        str1 = str2;
        // Verify
        assert(str1 == str3);
    }
    
    std::cout << "Done testing swap assign" << std::endl;
}