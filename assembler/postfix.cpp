///////////////////////////////////////////////////////
//
// File: postfix.cpp
// Date: Fall 2019
// Programmer: Paweena Manotipya
// Course: CS23001
// Description: Read infix file and convert to postfix file
//

#include "utilities.hpp"

void output_usage_and_exit(const char cmd[]);

int main(int argc, char const * argv[])
{
    if (argc < 2) { output_usage_and_exit(argv[0]); }
    
    // Open file, quit if open fails
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);
    if (!in) { std::cerr << "Couldn't open " << argv[1] << std::endl; exit(2); }   
    
    do {

      String line = get_line(in);

      // Ignore empty line, and convert infix to postfix
      if (line != "") {

          String postfix = infix_to_postfix(line);
             
          
          if (!out) {
              std::cout << "Infix Expression: " << line << std::endl;
              std::cout << "Postfix Expression: " << postfix << std::endl;
              //std::cout << std::endl;
              
              //String assembly = postfix_to_assembly(postfix, out);
          } else {
              out << "Infix Expression: " << line << std::endl;
              out << "Postfix Expression: " << postfix << std::endl; 
              //out << std::endl;
              
              //String assembly = postfix_to_assembly(postfix, out);
          }
      }
    
    } while (!in.eof());

    in.close(); 
    out.close();
}

void output_usage_and_exit(const char cmd[])
{
    // Print usage
    std::cerr << "Usage: " << cmd << " [input_file] [output_file (optional)]" << std::endl;
    // Exit with error
    exit(1);
}
