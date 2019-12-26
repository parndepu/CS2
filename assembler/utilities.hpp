#ifndef CS2_UTILITIES_HPP
#define CS2_UTILITIES_HPP

////////////////////////////////////////////////////////////////////////////
//
// File: utilities.hpp
//
// Programmer: Paweena Manotipya
// Date: Fall 2019
//

#include <fstream>
#include "stack.hpp"
#include "string.hpp"
#include <vector>

String get_line       (std::istream&);
String infix_to_postfix (String);
String postfix_to_assembly (String, std::ofstream&);
String evaluate(String, String, String, int, std::ofstream&);
String translate_operator(const String&);

#endif
