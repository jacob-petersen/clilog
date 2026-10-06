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
            freq_ = "";
            mode_ = "";
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

    utc_date_ = clilog::timeutils::get_utc_date();
    utc_time_ = clilog::timeutils::get_utc_time();

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
