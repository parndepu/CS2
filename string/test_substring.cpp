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
        
        // Verify
        assert(str1.substr(0, 4) == "hello");
    }

    // TODO: need to add more test case
    
    std::cout << "Done testing substring" << std::endl;
}
