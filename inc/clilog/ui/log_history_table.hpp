/*
    Keep it simple, stupid.
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