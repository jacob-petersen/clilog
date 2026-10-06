/*
    Keep it simple, stupid.

    This header defines clilog::LoggingScreen, which is the actual screen that most logging is done in.
    It is not to be confused with clilog::LogInputForm, which is the log entry panel that is set up in that 
    file and used here.

*/

#include "clilog/ui/log_history_table.hpp"
#include "clilog/ui/log_input_form.hpp"
#include "clilog/ui/logging_screen.hpp"
#include "clilog/ui/header.hpp"

clilog::LoggingScreen::LoggingScreen(clilog::LogStore& log_store) {
    using namespace ftxui;

    log_input_form_ = ftxui::Make<clilog::LogInputForm>(log_store);
    log_history_ = ftxui::Make<clilog::LogHistoryTable>(log_store);

    container_ = Container::Vertical({
        log_input_form_, 
        log_history_
    });

    Add(container_);
}

ftxui::Element clilog::LoggingScreen::OnRender() {
    using namespace ftxui;
    return vbox({
        clilog::generate_header(),
        text(" "),
        hbox({
            text(" "),
            log_input_form_->Render(),
            text(" ")    
        }),
        separator(),
        hbox({
            text(" "),
            log_history_->Render(),
            text(" ")
        })
    });
}