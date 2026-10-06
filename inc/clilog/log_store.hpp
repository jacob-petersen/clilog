/*
    Keep it simple, stupid.
*/

#pragma once

#include <vector>

#include "clilog/log_entry.hpp"

namespace clilog {

class LogStore {

    private:
    std::vector<clilog::LogEntry> log_entry_buffer_;

    public:
    void add_log_entry(clilog::LogEntry log_entry);

    std::vector<clilog::LogEntry>& DEBUG_dump_entire_buffer();
    void DEBUG_generate_sample_log_entries(int n);

};

}