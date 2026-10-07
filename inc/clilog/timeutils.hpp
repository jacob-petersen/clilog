/**
 * 
 * @brief UTC time helper functions for clilog.
 * @author Jacob Petersen
 * 
 * Keep it simple, stupid.
 */

#pragma once

#include <string>

namespace clilog::timeutils {

/**
 * @brief Container containing a point in time to second precision.
 */
struct UTCTimePoint {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

/**
 * @brief Returns a `clilog::UTCTimePoint` with the current UTC time.
 */
clilog::timeutils::UTCTimePoint get_utc_time();
    
}