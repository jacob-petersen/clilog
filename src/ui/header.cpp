/*
    Keep it simple, stupid. 

    NOTHING IN THIS FILE SHOULD EVER BE CALLED BY ANYTHING OUTSIDE OF /ui !!!
    The global program header should be incorporated into the relevant UI page BEFORE it is handed to any renderer.

*/

#include <format>

#include "clilog/ui/header.hpp"

#include "ftxui/component/component.hpp"

#include "clilog/timeutils.hpp"

ftxui::Element clilog::generate_header() {
    using namespace ftxui;

    auto now = clilog::timeutils::get_utc_time();

    auto header = hbox(
        text(" clilog v0.1"),
        filler(),
        // text(clilog::timeutils::get_utc_datetime_string() + " ")
        text(std::format("{:04}-{:02}-{:02} {:02}:{:02}:{:02} UTC", now.year, now.month, now.day, now.hour, now.minute, now.second))
    ) | inverted;
    return header;   
}
