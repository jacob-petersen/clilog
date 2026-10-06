/*
    Keep it simple, stupid.

    These functions return the current UTC date, time, or both, formatted as a string. 
    Format: YYYY-MM-DD, HH:MM:SS

    TODO: In the future, the program should attempt to synchronize with an NTP server rather than relying on system time.

*/
#include "clilog/timeutils.hpp"

#include <chrono>
#include <string>

/*
    Explaining a few things:
    - "now" is the system time at the highest resolution possible in the system
    - "today" is the system time floored to the day, so it loses hours, minutes, and seconds resolution
    - year_month_day is an std::chrono type that allows the year, month, and day to be extracted
      (and then cast to int or something else useful)
    - hh_mm_ss is similar, except it needs a *duration* as input, a.k.a. the time between two points.
      this is also is needs .count()
*/
clilog::timeutils::UTCTimePoint clilog::timeutils::get_utc_time() {
    using namespace std::chrono;

    auto now = system_clock::now();
    auto today = floor<days>(now);
    year_month_day now_ymd {today};
    hh_mm_ss now_hhmmss {now - today};

    clilog::timeutils::UTCTimePoint result = {
        .year = static_cast<int>(now_ymd.year()),
        .month = static_cast<int>(static_cast<unsigned>(now_ymd.month())),
        .day = static_cast<int>(static_cast<unsigned>(now_ymd.day())),
        .hour = static_cast<int>(now_hhmmss.hours().count()),
        .minute = static_cast<int>(now_hhmmss.minutes().count()),
        .second = static_cast<int>(now_hhmmss.seconds().count())
    };

    return result;

}
