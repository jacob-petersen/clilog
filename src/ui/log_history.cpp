/*
    Keep it simple, stupid.
*/

#include <random>
#include <format>

#include "ftxui/component/component.hpp"
#include "ftxui/dom/table.hpp"

#include "clilog/ui/log_history.hpp"
#include "clilog/log_store.hpp"

clilog::LogHistoryTable::LogHistoryTable(clilog::LogStore& log_store)
    : log_store_(log_store) 
{}

ftxui::Element clilog::LogHistoryTable::OnRender() {
    using namespace ftxui;

    auto sample_data = log_store_.DEBUG_dump_entire_buffer();
    std::vector<std::vector<std::string>> table_data = {{"UTC Date", "UTC Time", "Call", "Freq", "Mode", "RST Sent", "RST Rcvd", "Comment"}};

    for (clilog::LogEntry entry: sample_data) {
        std::vector<std::string> row = {
            entry.utc_date,
            entry.utc_time,
            entry.call,
            entry.freq,
            entry.mode,
            entry.rst_sent,
            entry.rst_rcvd,
            entry.comment
        };
        table_data.push_back(row);
    }

    auto table = Table(table_data);
    table.SelectAll().SeparatorVertical(LIGHT);
    table.SelectRow(0).Border();
    table.SelectRow(0).DecorateCells(bold);
    return table.Render();

}