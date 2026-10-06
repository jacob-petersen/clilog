/*
    Keep it simple, stupid.
*/

#include "ftxui/component/component.hpp"
#include "ftxui/component/event.hpp"

#include "clilog/ui/log_input_form.hpp"
#include "clilog/timeutils.hpp"

// Need to pass reference immediately so it doesn't get copied
clilog::LogInputForm::LogInputForm(clilog::LogStore& log_store)
    : log_store_(log_store)
{
    using namespace ftxui;
    
    input_utc_date_ = Input(&utc_date_);
    input_utc_time_ = Input(&utc_time_);
    input_call_ = Input(&call_);
    input_freq_ = Input(&freq_);
    input_mode_ = Input(&mode_);
    input_rst_sent_ = Input(&rst_sent_);
    input_rst_rcvd_ = Input(&rst_rcvd_);
    input_comment_ = Input(&comment_);

    // Call field input validator
    input_call_ |= CatchEvent([&] (Event event) {
        if (!event.is_character()) return false;

        // Allowed inputs: A-Z, 0-9, /, -
        if ( 
            (event.character()[0] >= 65 && event.character()[0] <= 90) ||
            (event.character()[0] >= 48 && event.character()[0] <= 57) ||
            event.character()[0] == 45 || event.character()[0] == 47
        ) {
            // Return false because these characters are OK, we don't need to intercept them
            return false;
        } else if (event.is_character() && event.character()[0] >= 97 && event.character()[0] <= 122) {
            // Call the input's OnEvent() with the modified character
            return input_call_->OnEvent(Event::Character(static_cast<char>(event.character()[0] - 32)));
        }

        return true;
        
    });

    // Freq field input validator
    input_freq_ |= CatchEvent([&] (Event event) {
        if (!event.is_character()) return false;

        // Allowed inputs: 0-9, .
        if ( (event.character()[0] >= 48 && event.character()[0] <= 57) || event.character()[0] == 46 ) {
            return false;
        }

        return true;
    });

    container_ = Container::Horizontal({
        input_utc_date_,
        input_utc_time_,
        input_call_,
        input_freq_,
        input_mode_,
        input_rst_sent_,
        input_rst_rcvd_,
        input_comment_
    });

    // "Enter" event handler. Returning true swallows the event (so nothing else tries handle it)
    container_ |= CatchEvent([&] (Event event) {
        if (event == Event::Return) {
            clilog::LogEntry log_entry {
                .utc_date = utc_date_,
                .utc_time = utc_time_,
                .call = call_,
                .freq = freq_,
                .mode = mode_,
                .rst_sent = rst_sent_,
                .rst_rcvd = rst_rcvd_,
                .comment = comment_
            };
            log_store_.add_log_entry(log_entry);

            utc_date_ = "";
            utc_time_ = "";
            call_ = "";
            // freq_ = "";
            // mode_ = "";
            rst_sent_ = "";
            rst_rcvd_ = "";
            comment_ = "";

            return true;
        }

        return false;
    });

    Add(container_);

}

ftxui::Element clilog::LogInputForm::OnRender() {
    using namespace ftxui;

    auto now = clilog::timeutils::get_utc_time();
    utc_date_ = std::format("{:04}-{:02}-{:02}", now.year, now.month, now.day);
    utc_time_ = std::format("{:02}:{:02}:{:02}", now.hour, now.minute, now.second);

    return 
        vbox({
            hbox({
                hbox({
                    text("UTC Date"),
                    separator(),
                    input_utc_date_->Render() | size(WIDTH, EQUAL, 11) | underlined
                }) | border,
                hbox({
                    text("UTC Time"),
                    separator(),
                    input_utc_time_->Render() | size(WIDTH, EQUAL, 9) | underlined
                }) | border,
                hbox({
                    text("Call"),
                    separator(),
                    input_call_->Render() | size(WIDTH, EQUAL, 11) | underlined
                }) | border,
                hbox({
                    text("Freq"),
                    separator(),
                    input_freq_->Render() | size(WIDTH, EQUAL, 11) | underlined
                }) | border,
                hbox({
                    text("Mode"),
                    separator(),
                    input_mode_->Render() | size(WIDTH, EQUAL, 9) | underlined
                }) | border,
                hbox({
                    text("RST Sent"),
                    separator(),
                    input_rst_sent_->Render() | size(WIDTH, EQUAL, 9) | underlined
                }) | border,
                hbox({
                    text("RST Rcvd"),
                    separator(),
                    input_rst_rcvd_->Render() | size(WIDTH, EQUAL, 9) | underlined
                }) | border
            }) | size(HEIGHT, EQUAL, 3),
            hbox({
                text("Comment"),
                separator(),
                input_comment_->Render() | size(WIDTH, GREATER_THAN, 10) | flex | underlined
            }) | border
        });

}
