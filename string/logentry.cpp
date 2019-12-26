///////////////////////////////////////////////////////////
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        Fall 2019
// Author:      Paweena Manotipya
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
       
    // Get all text from log
    std::vector<String> vec = s.split(' ');
 
    if (vec.size() == 10) {
        // Set host
        host = vec[0];
        // Set date and time
        std::vector<String> vec_datetime = vec[3].split(':');
        std::vector<String> vec_date = vec_datetime[0].split('/');
        
        // Set date
        String day = vec_date[0];
        String month = vec_date[1];
        int year = parse_integer(vec_date[2]);
        date.set_date(day, month, year);
    
        // Set time
        int hour = parse_integer(vec_datetime[1]);
        int minute = parse_integer(vec_datetime[2]);    
        int second = parse_integer(vec_datetime[3]);
        time.set_time(hour, minute, second);

        // Set request and status
        request = vec[5] + " " + vec[6] + " " + vec[7];
        status = vec[8];
        
        // Set number of bytes
        number_of_bytes = (vec[9] == '-') ? 0 : parse_integer(vec[9]);
    } else {
        // Set all to empty
        host = "";
        date.set_date("", "", 0);
        time.set_time(0, 0, 0);
        request = "";
        status = "";
        number_of_bytes = 0;
    }

    vec.clear();
    vec.shrink_to_fit(); 
}

//////////////////////////////////////////////////////////
// REQUIRES:  
// ENSURES: 
//
std::vector<LogEntry> parse(std::istream& in) {
    
    std::vector<LogEntry> result;

    do {

        String line = get_line(in);
        LogEntry log(line);
        result.push_back(log);
 
    } while (!in.eof());
    
    return result;
}

///////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES:
//
std::ostream& operator<<(std::ostream& out, const LogEntry& log) {
   
   out << log.host << ' '; 
   out << log.date.get_day() << '/' << log.date.get_month() << '/' << log.date.get_year() << ':';
   out << log.time.get_hour() << ':' << log.time.get_minute() << ':' << log.time.get_second() << ']' << ' ';
   out << log.request << ' ';
   out << log.status << ' ';
   out << log.number_of_bytes;    
   
   return out;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> & logs) {
 
   for (auto log = logs.begin(); log != logs.end(); ++log) {
       if (log->get_host() != "") out << *log << '\n';       
   }    
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {

    for (auto log = logs.begin(); log != logs.end(); ++log) {
        if (log->get_host() != "") out << log->get_host() << '\n';
    }
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> & logs) {
    
    int count = 0;

    for (auto log = logs.begin(); log != logs.end(); ++log) {
        count += log->get_byte();
    }    

    return count;
}

///////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES:
//
int parse_integer(String s) {
    
    int digits = 1;
    int value = 0;
    
    for (int i = 0; i < s.length(); ++i) {
        value += (int(s[i]) - int('0')) * digits; 
        digits *= 10;  
    }

    return value;
}

//////////////////////////////////////////////////////////
// REQUIRES:
// ENSURES:
//
String get_line(std::istream& in) {
    
    String line;
    char ch = '\0';
    
    in.get(ch);
    while (ch != '\n' && !in.fail()) {
        line += ch;
        in.get(ch);
    }
    
    return line;   
}
