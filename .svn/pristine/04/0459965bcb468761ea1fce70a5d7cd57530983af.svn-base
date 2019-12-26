// String class test program
//
// Test: split string and store it in vector
//

#include "string.hpp"
#include <cassert>

int main()
{
    {
        // TEST  
        String str1("abc ef gh");
        std::vector<String> str2 = str1.split(' ');
        std::vector<String> str3{"abc", "ef", "gh"};
        
        // VERIFY
        assert(str2 == str3);
    }

    {
        // TEST
        String str1("-a--b-");
        std::vector<String> str2 = str1.split('-');
        std::vector<String> str3{"", "a", "", "b", ""};
        
        // VERIFY
        assert(str2 == str3);
    }

    std::cout << "Done testing split string" << std::endl;
}
