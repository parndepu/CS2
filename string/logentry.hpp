#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        Fall 2019
// Author:      Paweena Manotipya
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
            Date() {};
    void    set_date(String d, String m, int  y) { day = d; month = m; year = y; };
    String  get_day() const { return day; };
    String  get_month() const { return month; };
    int     get_year() const { return year; };
private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time() {};
    void    set_time(int h, int m, int s) { hour = h; minute = m; second = s; };
    int     get_hour() const { return hour; };
    int     get_minute() const { return minute; };
    int     get_second() const { return second; };
  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
            LogEntry() {};
            LogEntry(String);
    String  get_host() const { return host; };
    int     get_byte() const { return number_of_bytes; };    

    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);

private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);
int                     parse_integer(String);
String                  get_line    (std::istream&);
#endif
