/*
    Keep it simple, stupid.
*/

#include <string>
#include <vector>

#include "ftxui/component/component.hpp"

#include "ui/main_menu.hpp"
#include "ui/header.hpp"

namespace clilog {

ftxui::Element generate_ascii_title();

/*
    Initialize menu_ and add it as a child of this component
*/
MainMenu::MainMenu() {
    using namespace ftxui;

    menu_ = Menu(&entries_, &selected_);
    Add(menu_);
    
}

/*
    Render the entire main menu screen
*/
ftxui::Element MainMenu::OnRender() {
    using namespace ftxui;
    return vbox(
        clilog::generate_header(),
        filler(),
        filler(),
        clilog::generate_ascii_title() | center,
        filler(),
        menu_->Render() | size(HEIGHT, EQUAL, entries_.size()) | size(WIDTH, EQUAL, 30) | border | center,
        filler(),
        filler()
    );
}

ftxui::Element generate_ascii_title() {
    using namespace ftxui;

    auto ascii_banner = vbox(
        text(" ######  ##       #### ##        #######   ######  \n##    ## ##        ##  ##       ##     ## ##    ## \n##       ##        ##  ##       ##     ## ##       \n##       ##        ##  ##       ##     ## ##   ####\n##       ##        ##  ##       ##     ## ##    ## \n##    ## ##        ##  ##       ##     ## ##    ## \n ######  ######## #### ########  #######   ######   "),
        hbox(text("Version 0.1"), filler(), text("Created by VE4JPX "))
    );

    return ascii_banner;
}

}