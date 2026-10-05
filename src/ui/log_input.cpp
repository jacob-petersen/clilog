/*
    Keep it simple, stupid.
*/

#include "clilog/ui/log_input.hpp"

clilog::LogInput::LogInput() {
    using namespace ftxui;
    
    input_utc_date_ = Input(&utc_date_);//, "UTC Date");
    input_utc_time_ = Input(&utc_time_);//, "UTC Time");
    input_call_ = Input(&call_);//, "Call");
    input_freq_ = Input(&freq_);//, "Frequency");
    input_mode_ = Input(&mode_);//, "Mode");
    input_rst_sent_ = Input(&rst_sent_);//, "RST Sent");
    input_rst_rcvd_ = Input(&rst_rcvd_);//, "RST Rcvd");
    input_comment_ = Input(&comment_);//, "Comment");

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

    Add(container_);

}

ftxui::Element clilog::LogInput::OnRender() {
    using namespace ftxui;

    return hbox({
        hbox({
            text("UTC Date"),
            separator(),
            input_utc_date_->Render() | size(WIDTH, EQUAL, 11) | inverted
        }) | border,
        hbox({
            text("UTC Time"),
            separator(),
            input_utc_time_->Render() | size(WIDTH, EQUAL, 9) | inverted
        }) | border,
        hbox({
            text("Call"),
            separator(),
            input_call_->Render() | size(WIDTH, EQUAL, 11) | inverted
        }) | border,
        hbox({
            text("Freq"),
            separator(),
            input_freq_->Render() | size(WIDTH, EQUAL, 11) | inverted
        }) | border,
        hbox({
            text("Mode"),
            separator(),
            input_mode_->Render() | size(WIDTH, EQUAL, 9) | inverted
        }) | border,
        hbox({
            text("RST Sent"),
            separator(),
            input_rst_sent_->Render() | size(WIDTH, EQUAL, 9) | inverted
        }) | border,
        hbox({
            text("RST Rcvd"),
            separator(),
            input_rst_rcvd_->Render() | size(WIDTH, EQUAL, 9) | inverted
        }) | border,
        hbox({
            text("Comment"),
            separator(),
            input_comment_->Render() | size(WIDTH, EQUAL, 11) | inverted
        }) | border
    }) | size(HEIGHT, EQUAL, 1);

}
