/*
    Keep it simple, stupid.

    This header defines the LogHistoryTable, which is the UI component that renders the log history.
    Currently non-focusable, but this will change in the future.

*/
#pragma once

#include <string>
#include <vector>

#include "ftxui/component/component.hpp"

#include "clilog/log_store.hpp"

namespace clilog {
 
class LogHistoryTable : public ftxui::ComponentBase {

    private:
    clilog::LogStore& log_store_;
    std::vector<std::vector<std::string>> DEBUG_generate_sample_data(int);

    public:
    LogHistoryTable(clilog::LogStore& log_store);
    ftxui::Element OnRender() override;
};

}