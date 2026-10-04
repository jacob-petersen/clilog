/*
    Keep it simple, stupid. 

    NOTHING IN THIS FILE SHOULD EVER BE CALLED BY ANYTHING OUTSIDE OF /ui !!!
    The global program header should be incorporated into the relevant UI page BEFORE it is handed to any renderer.

*/

#pragma once

#include "ftxui/component/component.hpp"

namespace clilog {

    ftxui::Element generate_header();

}
