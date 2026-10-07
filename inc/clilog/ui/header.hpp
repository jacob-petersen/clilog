/**
 * 
 * @brief Functions relating to the global program header that renders at the top of every screen.
 * @author Jacob Petersen
 * 
 * NOTHING IN THIS FILE SHOULD EVER BE CALLED BY ANYTHING OUTSIDE OF /ui !!!
 * The global program header should be incorporated into the relevant UI page BEFORE it is handed to any renderer.
 * 
 * Keep it simple, stupid.
 */

#pragma once

#include "ftxui/component/component.hpp"

namespace clilog {

/*
    @brief Returns the global program header to be rendered at the top of the screen at all times.
*/
ftxui::Element generate_header();

}
