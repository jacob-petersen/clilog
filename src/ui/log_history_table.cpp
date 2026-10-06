/*
    Keep it simple, stupid.
*/

#include <random>
#include <format>

#include "ftxui/component/component.hpp"
#include "ftxui/dom/table.hpp"

#include "clilog/ui/log_history_table.hpp"
#include "clilog/log_store.hpp"

/*
    log_store_ is a REFERENCE to a log_store object that will be created in main().
    We have to create it IMMEDIATELY in the constructor, hence this syntax.
    If we don't do this, a copy of log_store will be created, which will be 
    decoupled from the one in main, which we don't want.
*/
clilog::LogHistoryTable::LogHistoryTable(clilog::LogStore& log_store)
    : log_store_(log_store)
{}

ftxui::Element clilog::LogHistoryTable::OnRender() {
    using namespace ftxui;

    auto data = log_store_.DEBUG_dump_entire_buffer();
    std::vector<std::vector<std::string>> table_data = {{"UTC Date", "UTC Time", "Call", "Freq", "Mode", "RST Sent", "RST Rcvd", "Comment"}};

    for (clilog::LogEntry entry: data) {
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