/*
    Keep it simple, stupid.
*/

#pragma once

#include "ftxui/component/component.hpp"

#include "clilog/ui/log_input.hpp"

namespace clilog {
   
class LoggingScreen : public ftxui::ComponentBase {

    private:
    ftxui::Component log_input_;

    public:
    LoggingScreen();
    ftxui::Element OnRender() override;

};

}