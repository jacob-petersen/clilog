/*
    Keep it simple, stupid.
*/

#pragma once

#include "ftxui/component/component.hpp"

namespace clilog {
   
class LoggingScreen : public ftxui::ComponentBase {

    private:
    ftxui::Component log_input_;
    ftxui::Component log_history_;
    ftxui::Component container_;

    public:
    LoggingScreen();
    ftxui::Element OnRender() override;

};

}