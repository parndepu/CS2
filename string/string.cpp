///////////////////////////////////////////////////////
// File: string.cpp
// Date: Fall 2019
// Author: Paweena Manotipya
// Course: CS23001
// Description: String ADT methods and functions
//

#include "string.hpp"

// Empty string
String::String()
{
    stringSize = 1;
    str = new char[stringSize];
    str[0] = '\0';
}

// String(10) - capacity 10, empty string
String::String(int n)
{
    stringSize = n + 1;
    str = new char[stringSize];
    str[0] = '\0';
}

// String('x')
String::String(char ch)
{
    if (ch != '\0') {
        stringSize = 2;
        str = new char[stringSize];
        str[0] = ch; str[1] = '\0';
    } else {
        stringSize = 1;
        str = new char[stringSize];
        str[0] = '\0';
    }
}

// String("abc")
String::String(const char c_str[])
{
    // count size of string
    int size = 0;
    while(c_str[size++] != '\0');

    stringSize = size;
    str = new char[stringSize];

    for (int i = 0; i < size; ++i) {
        str[i] = c_str[i];
    }
}

// String(10, "abc") - capacity 10 with "abc"
String::String(int n, const char c_str[]) 
{
    stringSize = n + 1;
    str = new char[stringSize];

    for (int i = 0; i < stringSize; ++i) {
        str[i] = c_str[i];
    }
    
    str[stringSize - 1] = '\0';
    //std::cout << capacity() << std::endl;
}

// Copy Constructor
String::String(const String& rhs) 
{
    stringSize = rhs.stringSize;
    str = new char[stringSize];

    for (int i = 0; i < stringSize; ++i) {
        str[i] = rhs.str[i];
    }
}

// Destructor
String::~String()
{
    delete[] str;
}

// Constant time swap
void String::swap(String& rhs)
{
    // Swap size
    int temp_size = rhs.stringSize;
    rhs.stringSize = stringSize;
    stringSize = temp_size;

    // Swap string
    char * temp_str = rhs.str;
    rhs.str = str;
    str = temp_str;
}

// Assignment Copy
String& String::operator=(String rhs) 
{
    delete [] str;
    
    stringSize = rhs.stringSize;
    str = new char[stringSize];

    for (int i = 0; i < stringSize; ++i) {
        str[i] = rhs.str[i];
    }

    return * this;
}

// Accessor/Modifier
char& String::operator[](int i)
{
    return str[i];
}

// Accessor
char String::operator[](int i) const
{
    return str[i];
}

// Max chars that can be stored (not including null)
int String::capacity() const
{
    int cap = 0;
    for (int i = 0; i < stringSize - 1; ++i) { cap++; }
    return cap;
}

// Resets capacity to N, keeps string intact 
void String::resetCapacity(int n) 
{
    // Change capacity
    stringSize = n;
    
    char *tempStr = new char[stringSize];

    for (int i = 0; i < stringSize; ++i) {
        tempStr[i] = str[i];
    }
     
    if (length() < n) {
        tempStr[length()] = '\0';
    } else {
        tempStr[n] = '\0';
    } 

    delete [] str;
    str = tempStr;
}

// Actual number of chars in string
int String::length() const
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    return len;
}

// Concat string operator
String String::operator+(const String& rhs) const
{
    int new_size = length() + rhs.length() + 1;

    String result(new_size);

    // Add left 
    for (int i = 0; i <= length(); ++i) { result.str[i] = str[i]; }

    // Add right
    for (int i = 0; i <= rhs.length(); ++i) { result.str[length() + i] = rhs.str[i]; }

    result.str[length() + rhs.length()] = '\0';
     
    return result;
}

// Assign concat string operator
String& String::operator+=(const String& rhs)
{  
    int new_size = length() + rhs.length() + 1;
    resetCapacity(new_size);
    
    int rhsIndex = 0;
    for (int i = length(); i < new_size; ++i) {
        str[i] = rhs.str[rhsIndex];
        ++rhsIndex; 
    }    

    return * this;
}

// Equal operator
bool String::operator==(const String& rhs) const
{
    if (length() != rhs.length()) return false;

    for (int i = 0; i < length(); ++i) {
        if (str[i] != rhs.str[i]) return false;
    }

    return true;
}

// Less than operator
bool String::operator<(const String& rhs) const
{   
    int len = (length() > rhs.length()) ? rhs.length() : length();

    int i = 0;
    while ( i < len) {
        if (str[i] < rhs.str[i]) {
            return true;
        }

        if ( i == len - 1) {
            if (str[i] > rhs.str[i]) { return false; }
        }
        ++i;
    }  

    return (length() < rhs.length()) ? true : false;
}

// The sub-string from staring position to ending position
String String::substr(int start, int end) const
{   
    int size = (start >= end) ? 1 : (end - start) + 1; 
    

    String result(size);	
    int j = 0;
    for (int i = start; i <= end; ++i) {
        result[j] = str[i];
        j++;
    }
    result[size] = '\0';
    return result;
}

//Find location of charater starting at a position
int String::findch(int pos, char ch) const
{
    for (int i = pos; i < stringSize; ++i) {
        if (str[i] == ch) {
            return i;
        } 
    }
    return -1;
}

// Find location of str starting at a position
int String::findstr(int pos, const String& find) const
{
    int index = -1;    
    int len = find.length() - 1;   
     
    for (int i = pos; i < length(); ++i) {
        if (substr(i, i + len).length() == find.length()) {
            if (substr(i, i + len) == find) { return i; }
            len -= 1;          
        }
        len += 1;
    }    

    return index;
}

// Overload insertion operator
std::istream& operator>>(std::istream& in, String& rhs)
{
    in >> rhs.str;
    return in;
}

// Overload extraction operator
std::ostream& operator<<(std::ostream& out, const String& rhs)
{
    for (int i = 0; i < rhs.length(); ++i)
        out << rhs.str[i];
    return out;
}

// Split string by character
std::vector<String> String::split(char ch) const
{
    std::vector<String> v;
    
    int pos = 0;
    int foundPos = findch(pos, ch);

    if (foundPos != -1) {

        do {

            // Add split string to vector
            v.push_back(substr(pos, foundPos - 1));
            
            // Calculate next starting position
            pos = foundPos + 1;
            foundPos = findch(pos, ch);
       
        } while (foundPos != -1);
           
    }
    
    // Add last split string to vector
    v.push_back(substr(pos, length() - 1));
    
    // Debug
    // for (auto i = v.begin(); i != v.end(); ++i) { std::cout << *i << std::endl; }

    return v;
}

////////////////////////////////////////////////////////
// Other relational operators
//
String operator+(const char word[], const String& rhs)
{
    String result;
    String lhs(word);

    // Add left
    for (int i = 0; i < lhs.length(); ++i) {
        result[i] = lhs[i];
    }

    // Add right
    for (int i = 0; i < rhs.length(); ++i) {
        result[lhs.length() + i] = rhs[i];
    }

    result[lhs.length() + rhs.length()] = '\0';
    return result;
}
String operator+(char ch, const String& rhs)
{
    String result;
    String lhs(ch);

    // Add left
    for (int i = 0; i < lhs.length(); ++i) {
        result[i] = lhs[i];
    }

    // Add right
    for (int i = 0; i < rhs.length(); ++i) {
        result[lhs.length() + i] = rhs[i];
    }

    result[lhs.length() + rhs.length()] = '\0';
    return result;
}

bool operator==(const char word[], const String& rhs)
{
    String lhs(word);

    if (lhs.length() != rhs.length()) return false;

    for (int i = 0; i < lhs.length(); ++i) {
        if (lhs[i] != rhs[i]) return false;
    }

    return true;
}

bool operator==(char ch, const String& rhs)
{
    String lhs(ch);

    if (lhs.length() != rhs.length()) return false;

    for (int i = 0; i < lhs.length(); ++i) {
        if (lhs[i] != rhs[i]) return false;
    }

    return true;
}

bool operator<(const char word[], const String& rhs)
{
    int i = 0;
    String lhs(word);
    bool less_than = false;

    while (lhs[i] != '\0' && rhs[i] != '\0') {
        if (lhs[i] > rhs[i]) return false;
        if (lhs[i] < rhs[i]) less_than = true;
        ++i;
    }

    if (lhs[i] == '\0') return true;
	if (less_than && (rhs[i] == '\0')) return true;
    if (less_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return true;
	if (!less_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return false;
	return false;
}

bool operator<(char ch, const String& rhs)
{
    int i = 0;
    String lhs(ch);
    bool less_than = false;

    while (lhs[i] != '\0' && rhs[i] != '\0') {
        if (lhs[i] > rhs[i]) return false;
        if (lhs[i] < rhs[i]) less_than = true;
        ++i;
    }

    if (lhs[i] == '\0') return true;
	if (less_than && (rhs[i] == '\0')) return true;
    if (less_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return true;
	if (!less_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return false;
	return false;
}

bool operator<=(const String& lhs, const String& rhs)
{
    int i = 0;
    bool less_than = false;

    while (lhs[i] != '\0' && rhs[i] != '\0') {
        if (lhs[i] > rhs[i]) return false;
        if (lhs[i] <= rhs[i]) less_than = true;
        ++i;
    }

    if (lhs[i] == '\0') return true;
	if (less_than && (rhs[i] == '\0')) return true;
    if (less_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return true;
	if (!less_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return false;
	return false;
}

bool operator!=(const String& lhs, const String& rhs)
{
    if (lhs.length() != rhs.length()) return true;

    for (int i = 0; i < lhs.length(); ++i) {
        if (lhs[i] != rhs[i]) return true;
    }

    return false;
}

bool operator>=(const String& lhs, const String& rhs)
{
    int i = 0;
    bool more_than = false;

    while (lhs[i] != '\0' && rhs[i] != '\0') {
        if (lhs[i] < rhs[i]) return false;
        if (lhs[i] >= rhs[i]) more_than = true;
        ++i;
    }

    if (lhs[i] == '\0') return true;
	if (more_than && (rhs[i] == '\0')) return true;
    if (more_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return true;
	if (!more_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return false;
	return false;
}

bool operator>(const String& lhs, const String& rhs)
{
    int i = 0;
    bool more_than = false;

    while (lhs[i] != '\0' && rhs[i] != '\0') {
        if (lhs[i] < rhs[i]) return false;
        if (lhs[i] > rhs[i]) more_than = true;
        ++i;
    }

    if (lhs[i] == '\0') return true;
	if (more_than && (rhs[i] == '\0')) return true;
    if (more_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return true;
	if (!more_than && (lhs[i] == '\0') && (rhs[i] == '\0')) return false;
	return false;
}
