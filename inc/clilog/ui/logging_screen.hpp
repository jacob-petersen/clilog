/*
    Keep it simple, stupid.

    This header defines the LoggingScreen, which is the fully rendered screen that contains the logging input
    form (log_input_form_) and the logging history table (log_history_table)  

*/

#pragma once

#include "ftxui/component/component.hpp"

namespace clilog {
   
class LoggingScreen : public ftxui::ComponentBase {

    private:
    ftxui::Component log_input_form_;
    ftxui::Component log_history_table_;
    ftxui::Component container_;

    public:
    LoggingScreen(clilog::LogStore& log_store);
    ftxui::Element OnRender() override;

};

}