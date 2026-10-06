/*
    Keep it simple, stupid.
*/

#pragma once

#include <string>

namespace clilog::timeutils {

    struct UTCTimePoint {
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
    };

    clilog::timeutils::UTCTimePoint get_utc_time();

    // std::string get_utc_date_string();
    // std::string get_utc_time_string();
    // std::string get_utc_datetime_string();
    
}