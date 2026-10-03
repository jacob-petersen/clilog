#include <string>
#include <vector>

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"

#include "ui/header.hpp"

int main() {

    using namespace ftxui;

    std::vector<std::string> menu_items = {
        "Open last logbook",
        "Open logbook",
        "Create new logbook",
        "Settings",
        "Exit"
    };
    int selected = 0;

    auto ascii_banner = vbox(
        text(" ######  ##       #### ##        #######   ######  \n##    ## ##        ##  ##       ##     ## ##    ## \n##       ##        ##  ##       ##     ## ##       \n##       ##        ##  ##       ##     ## ##   ####\n##       ##        ##  ##       ##     ## ##    ## \n##    ## ##        ##  ##       ##     ## ##    ## \n ######  ######## #### ########  #######   ######   "),
        hbox(text("Version 0.1"), filler(), text("Created by VE4JPX "))
    );

    auto menu = Menu(&menu_items, &selected);
    auto main_renderer = Renderer(menu, [&] {
        return vbox(
            clilog::generate_header(),
            filler(),
            filler(),
            ascii_banner | center,
            filler(),
            menu->Render() | size(HEIGHT, EQUAL, menu_items.size()) | size(WIDTH, EQUAL, 30) | border | center,
            filler(),
            filler()
        );
    });

    auto screen = App::Fullscreen();
    screen.Loop(main_renderer);
}