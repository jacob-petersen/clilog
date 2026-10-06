/*
    Keep it simple, stupid.

    NOTHING IN THIS FILE SHOULD EVER BE USED DIRECTLY IN MAIN!
    Build the screen you want this menu on first, then use that.

    This header defines clilog::LogInputForm, which is the log data entry form that is used in the main logging screen.

*/

#pragma once

#include <string>

#include "ftxui/component/component.hpp"

#include "clilog/log_store.hpp"

namespace clilog {

class LogInputForm : public ftxui::ComponentBase {

    private:
    clilog::LogStore& log_store_;
    
    std::string utc_year_;
    std::string utc_month_;
    std::string utc_day_;
    std::string utc_hour_;
    std::string utc_minute_;
    std::string utc_second_;

    std::string call_;
    std::string freq_;
    std::string mode_;
    std::string rst_sent_;
    std::string rst_rcvd_;
    std::string comment_;

    ftxui::Component input_utc_year_;
    ftxui::Component input_utc_month_;
    ftxui::Component input_utc_day_;
    ftxui::Component input_utc_hour_;
    ftxui::Component input_utc_minute_;
    ftxui::Component input_utc_second_;

    ftxui::Component input_call_;
    ftxui::Component input_freq_;
    ftxui::Component input_mode_;
    ftxui::Component input_rst_sent_;
    ftxui::Component input_rst_rcvd_;
    ftxui::Component input_comment_;

    ftxui::Component container_;

    public:
    LogInputForm(clilog::LogStore& log_store);
    ftxui::Element OnRender() override;
};

}