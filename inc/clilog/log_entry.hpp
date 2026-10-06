/*
    Keep it simple, stupid.

    LogEntry is the main data structure that log entry data is stored in.

*/

#pragma once

#include <string>

namespace clilog {

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