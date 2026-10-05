/*
    Keep it simple, stupid.

    NOTHING IN THIS FILE SHOULD EVER BE USED DIRECTLY IN MAIN!
    Build the screen you want this menu on first, then use that.

*/

#pragma once

#include <string>

#include "ftxui/component/component.hpp"

namespace clilog {

class LogInput : public ftxui::ComponentBase {

    private:
    std::string utc_date_;
    std::string utc_time_;
    std::string call_;
    std::string freq_;
    std::string mode_;
    std::string rst_sent_;
    std::string rst_rcvd_;
    std::string comment_;

    ftxui::Component input_utc_date_;
    ftxui::Component input_utc_time_;
    ftxui::Component input_call_;
    ftxui::Component input_freq_;
    ftxui::Component input_mode_;
    ftxui::Component input_rst_sent_;
    ftxui::Component input_rst_rcvd_;
    ftxui::Component input_comment_;

    ftxui::Component container_;

    public:
    LogInput();
    ftxui::Element OnRender() override;
};

}