///////////////////////////////////////////////////////
// File: utilities.cpp
// Date: Fall 2019
// Programmer: Paweena Manotipya
// Course: CS23001
// Description: utilities function definitions

#include "utilities.hpp"

// Get line of string
String get_line(std::istream& in)
{
    String line;
    char ch = '\0';

    in.get(ch);
    while (ch != '\n' && !in.fail()) {
        line += ch;
        in.get(ch);
    }

    return line;
}

// Convert infix to postfix
String infix_to_postfix(String infix)
{
    std::vector<String> tokens = infix.split(' ');
    stack<String> s;    

    for (std::vector<String>::size_type idx = 0; idx < tokens.size() - 1; ++idx) {
        // Read token
        String token = tokens[idx];
        // Convert to postfix
        if (token != ";") {
            if (token == ")") {
                String right = s.pop();
                String oper = s.pop();
                String left = s.pop();
                s.push(left + right + oper);
            } else {
                if (token != "(") s.push(token + " ");
            }
        }
    }
    
    return s.top();  
}

// Convert postfix to assembly language and write to current file
String postfix_to_assembly(String postfix, std::ofstream& out)
{
    int TMPn = 0;
    std::vector<String> tokens = postfix.split(' ');
    stack<String> s;

    for (std::vector<String>::size_type idx = 0; idx < tokens.size() - 1; ++idx) {
        // Read token
        String token = tokens[idx];
  
        if (token != "+" && token != "-" && token != "/" && token != "*") {
            s.push(token);
        } else {
            String right = s.pop();
            String left = s.pop();
            // Evaluate and store temporary memory locations
            s.push(evaluate(left, token, right, ++TMPn, out));
        }
    }

    return postfix;
}

// Evaluate
String evaluate(String left, String oper, String right, int TMPn, std::ofstream& out)
{
    // Convert ch to string   
    char ch = '0' + TMPn;
    String TMP = "TMP";
    String n = String(ch);
    
    // Print out by default, or write to file
    if (!out) {
        std::cout << "   " << "LD" << "     " << left << std::endl;
        std::cout << "   " << translate_operator(oper) << "     " << right << std::endl;
        std::cout << "   " << "ST" << "     " << TMP + n << std::endl;
    } else {
        out << "   " << "LD" << "     " << left << std::endl;
        out << "   " << translate_operator(oper) << "     " << right << std::endl;
        out << "   " << "ST" << "     " << TMP + n << std::endl;
    } 

    return TMP + n;
}

// Translate operater to assembly language
String translate_operator(const String& oper) 
{
    if (oper == "+") return "AD";
    if (oper == "-") return "SB";
    if (oper == "*") return "MU";
    if (oper == "/") return "DV";
    return "  ";
}

