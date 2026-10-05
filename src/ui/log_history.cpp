/*
    Keep it simple, stupid.
*/

#include <random>
#include <format>

#include "ftxui/component/component.hpp"
#include "ftxui/dom/table.hpp"

#include "clilog/ui/log_history.hpp"

clilog::LogHistoryTable::LogHistoryTable() {
    return;
}

ftxui::Element clilog::LogHistoryTable::OnRender() {
    using namespace ftxui;
    auto sample_data = DEBUG_generate_sample_data(10);
    // std::string s;

    // for (std::vector<std::string> row: sample_data) {
    //     for (std::string col: row) {
    //         s += col + " ";
    //     }
    //     s += "\n";
    // }

    // return paragraph(s);

    auto table = Table(sample_data);
    // table.SelectAll().SeparatorVertical(LIGHT);
    return table.Render();

}

std::vector<std::vector<std::string>> clilog::LogHistoryTable::DEBUG_generate_sample_data(int n) {

    std::vector<std::vector<std::string>> data = {{"UTC Date", "UTC Time", "Call", "Freq", "Mode", "RST Sent", "RST Rcvd", "Comment"}};

    for (int i = 0; i < n; i++) {
        std::vector<std::string> row;    
        std::string s;

        // Generate random date string
        int year = 1900 + rand() % (2026 - 1900 + 1);
        int month = 1 + rand() % (12 - 1 + 1);
        int day = 1 + rand() % (31 - 1 + 1);
        s = std::format("{}-{:02}-{:02}", year, month, day);   
        row.push_back(s);

        // Generate random time string
        int hour = 0 + rand() % (23 - 0 + 1);
        int minute = 0 + rand() % (59 - 0 + 1);
        int second = 0 + rand() % (59 - 0 + 1);
        s = std::format("{:02}:{:02}:{:02}", hour, minute, second);
        row.push_back(s);

        // Generate random callsign 
        const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        s = "";
        int len = 4 + rand() % (6 - 4 + 1);
        for (int i = 0; i < len; i++) {
            s += alphabet[rand() % sizeof(alphabet) - 1];
        }
        row.push_back(s);

        // Generate random frequency
        s = std::format("{}", 1000 * (14000 + rand() % (14350 - 14000 + 1)));
        row.push_back(s);

        // Generate a random mode
        std::vector<std::string> modes = {"SSB", "CW", "FT8", "RTTY", "WSPR"};
        row.push_back(modes[rand() % (modes.size() - 1)]);

        // Generate a random RST Sent
        row.push_back(std::format("{}", 11 + rand() % (59 - 11 + 1)));

        // Generate a random RST Rcvd
        row.push_back(std::format("{}", 11 + rand() % (59 - 11 + 1)));
        
        // Generate a random comment
        const char alphabet2[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
        len = 20 + rand() % (100 - 20 + 1);
        s = "";
        for (int i = 0; i < len; i++) {
            s += alphabet2[rand() % (sizeof(alphabet2) - 1)];
        }
        row.push_back(s);

        data.push_back(row);
    }

    return data;
    
}