/*
    Keep it simple, stupid.
*/

#pragma once

#include <string>

namespace clilog::timeutils {
    std::string get_utc_date();
    std::string get_utc_time();
    std::string get_utc_datetime();
}