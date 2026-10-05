/*
    Keep it simple, stupid.
*/

#include <string>
#include <format>
#include <vector>

#include "clilog/log_store.hpp"

void clilog::LogStore::add_log_entry(clilog::LogEntry log_entry) {
    log_entry_buffer_.push_back(log_entry);
}

std::vector<clilog::LogEntry>& clilog::LogStore::DEBUG_dump_entire_buffer() {
    return log_entry_buffer_;
}

void clilog::LogStore::DEBUG_generate_sample_log_entries(int n) {

    for (int i = 0; i < n; i++) {
        clilog::LogEntry entry;    
        std::string s;

        // Generate random date string
        int year = 1900 + rand() % (2026 - 1900 + 1);
        int month = 1 + rand() % (12 - 1 + 1);
        int day = 1 + rand() % (31 - 1 + 1);
        s = std::format("{}-{:02}-{:02}", year, month, day);   
        entry.utc_date = s;

        // Generate random time string
        int hour = 0 + rand() % (23 - 0 + 1);
        int minute = 0 + rand() % (59 - 0 + 1);
        int second = 0 + rand() % (59 - 0 + 1);
        s = std::format("{:02}:{:02}:{:02}", hour, minute, second);
        entry.utc_time = s;

        // Generate random callsign 
        const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        s = "";
        int len = 4 + rand() % (6 - 4 + 1);
        for (int i = 0; i < len; i++) {
            s += alphabet[rand() % sizeof(alphabet) - 1];
        }
        entry.call = s;

        // Generate random frequency
        s = std::format("{}", 1000 * (14000 + rand() % (14350 - 14000 + 1)));
        entry.freq = s;

        // Generate a random mode
        std::vector<std::string> modes = {"SSB", "CW", "FT8", "RTTY", "WSPR"};
        entry.freq = modes[rand() % (modes.size() - 1)];

        // Generate a random RST Sent
        entry.rst_sent = std::format("{}", 11 + rand() % (59 - 11 + 1));

        // Generate a random RST Rcvd
        entry.rst_rcvd = std::format("{}", 11 + rand() % (59 - 11 + 1));
        
        // Generate a random comment
        const char alphabet2[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
        len = 20 + rand() % (100 - 20 + 1);
        s = "";
        for (int i = 0; i < len; i++) {
            s += alphabet2[rand() % (sizeof(alphabet2) - 1)];
        }
        entry.comment = s;

        log_entry_buffer_.push_back(entry);
    }
    
}
