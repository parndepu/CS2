// Utilities test program
//
// Tests: infix to postfix
//

#include "utilities.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String infix = "( ( AX + ( BY * C ) ) / ( D4 - E ) );";
        
        // TEST
        String postfix = infix_to_postfix(infix);

        // VERIFY
        //assert(postfix == "AX BY C * + D4 E - /");
    }

    std::cout << "Done testing infix to postfix." << std::endl;
}
