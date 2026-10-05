/*
    Keep it simple, stupid.
*/
#pragma once

#include <string>
#include <vector>

#include "ftxui/component/component.hpp"

namespace clilog {
 
class LogHistoryTable : public ftxui::ComponentBase {
    private:
    std::vector<std::vector<std::string>> DEBUG_generate_sample_data(int);
    public:
    LogHistoryTable();
    ftxui::Element OnRender() override;
};

}