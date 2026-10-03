/*
    Keep it simple, stupid. 

    NOTHING IN THIS FILE SHOULD EVER BE CALLED BY ANYTHING OUTSIDE OF /ui !!!
    The global program header should be incorporated into the relevant UI page BEFORE it is handed to any renderer.

*/

#include "ftxui/component/component.hpp"

namespace clilog {

ftxui::Element generate_header() {
    using namespace ftxui;

    auto header = hbox(
        text(" clilog v0.1"),
        filler(),
        text("2026-01-01 00:00:00 UTC ")
    ) | inverted;
    return header;   
}

}