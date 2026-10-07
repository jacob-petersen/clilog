/**
 * 
 * @brief This header defines the LogStore object, which handles everything related to storing 
 * and retrieving logs.
 * @author Jacob Petersen
 * 
 * Keep it simple, stupid.
 */

#pragma once

#include <vector>

#include "clilog/log_entry.hpp"

namespace clilog {

/*
    @brief The object that stores and retrieves logs. Handles database persistence under the hood. 
*/
class LogStore {

    private:
    std::vector<clilog::LogEntry> log_entry_buffer_;

    public:
    void add_log_entry(clilog::LogEntry log_entry);
    
    // @brief DEBUG! Do not use in production code!
    std::vector<clilog::LogEntry>& DEBUG_dump_entire_buffer();
    // @brief DEBUG! Do not use in production code!
    void DEBUG_generate_sample_log_entries(int n);

};

}