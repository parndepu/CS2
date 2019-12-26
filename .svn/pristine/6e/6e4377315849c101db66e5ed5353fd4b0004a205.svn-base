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
        String str1('x');
        String str2("x");
        // Verify
        assert(str1 == 'x');
        assert(str2 == "x");
        assert(str1 == str2);
    }

    {
        // Setup
        String str1('x');
        String str2('y');
        // Verify
        assert(str1 == 'x');
        assert(str2 == "y");
        assert(!(str1 == str2));

        assert('x' == str1);
        assert("y" == str2);
        assert(!(str2 == str1));
    }
    
    std::cout << "Done testing ctor_char" << std::endl;
}