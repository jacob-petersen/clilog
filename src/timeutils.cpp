/*
    Keep it simple, stupid.

    These functions return the current UTC date, time, or both, formatted as a string. 
    Format: YYYY-MM-DD, HH:MM:SS

    TODO: In the future, the program should attempt to synchronize with an NTP server rather than relying on system time.

*/
#include "clilog/timeutils.hpp"

#include <chrono>
#include <string>

std::string clilog::timeutils::get_utc_date() {
    auto now = std::chrono::system_clock::now();
    auto now_seconds = std::chrono::floor<std::chrono::seconds>(now);
    return std::format("{:%Y-%m-%d}", now_seconds);
}

std::string clilog::timeutils::get_utc_time() {
    auto now = std::chrono::system_clock::now();
    auto now_seconds = std::chrono::floor<std::chrono::seconds>(now);
    return std::format("{:%H:%M:%S}", now_seconds);
}

std::string clilog::timeutils::get_utc_datetime() {
    auto now = std::chrono::system_clock::now();
    auto now_seconds = std::chrono::floor<std::chrono::seconds>(now);
    return std::format("{:%Y-%m-%d %H:%M:%S} UTC", now_seconds);
}
