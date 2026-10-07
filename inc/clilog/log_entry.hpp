/**
 * 
 * @brief Contains data structures relating to log objects, including `clilog::LogEntry`.
 * 
 * Keep it simple, stupid.
 */

#pragma once

#include <string>

namespace clilog {

/*
    @brief Container struct for minimum information required for a log entry 
    (`comment` can remain blank). 
*/
struct LogEntry {
    std::string utc_date;
    std::string utc_time;
    std::string call;
    std::string freq;
    std::string mode;
    std::string rst_sent;
    std::string rst_rcvd;
    std::string comment;
};

}