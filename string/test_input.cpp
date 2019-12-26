//  String test program
//
//  Tests: input stream
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        // TODO: need to fix this test
        String s1('\0');
        String s2("");
        assert(s1 == s2);
    }
    
    std::cout << "Done testing input" << std::endl;
}