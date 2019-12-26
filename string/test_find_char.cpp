//  String test program
//
//  Tests: find character in string
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
        assert(str1.findch(0, 'o') == 4);
    }

    {
        // Setup
        String str1("a b");
        
        // Verify
        assert(str1.findch(0, ' ') == 1);
        assert(str1.findch(2, ' ') == -1);
    }

    {
        // Setup
        String str1("x y");
        
        // Verify
        assert(str1.findch(1, 'x') == -1);
    }
    
    std::cout << "Done testing find_char" << std::endl;
}
