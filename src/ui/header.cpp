/*
    Keep it simple, stupid. 

    NOTHING IN THIS FILE SHOULD EVER BE CALLED BY ANYTHING OUTSIDE OF /ui !!!
    The global program header should be incorporated into the relevant UI page BEFORE it is handed to any renderer.

*/

#include "clilog/ui/header.hpp"

#include "ftxui/component/component.hpp"

#include "clilog/timeutils.hpp"

ftxui::Element clilog::generate_header() {
    using namespace ftxui;

    auto header = hbox(
        text(" clilog v0.1"),
        filler(),
        // text("2026-01-01 00:00:00 UTC ")
        text(clilog::timeutils::get_utc_datetime() + " ")
    ) | inverted;
    return header;   
}
