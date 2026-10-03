#include <string>
#include <vector>

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"

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

    auto header = hbox(
        text("clilog v0.1"),
        filler(),
        text("XXXX-XX-XX 00:00:00 UTC")
    ) | size(HEIGHT, EQUAL, 1) | inverted;

    auto ascii_banner = vbox(
        text(" ######  ##       #### ##        #######   ######  \n##    ## ##        ##  ##       ##     ## ##    ## \n##       ##        ##  ##       ##     ## ##       \n##       ##        ##  ##       ##     ## ##   ####\n##       ##        ##  ##       ##     ## ##    ## \n##    ## ##        ##  ##       ##     ## ##    ## \n ######  ######## #### ########  #######   ######   "),
        hbox(text("Version 0.1"), filler(), text("Created by VE4JPX "))
    );

    auto menu = Menu(&menu_items, &selected);
    auto main_renderer = Renderer(menu, [&] {
        return vbox(
            header,
            ascii_banner | center | flex,
            menu->Render() | size(HEIGHT, EQUAL, menu_items.size()) | size(WIDTH, EQUAL, 30) | border | center | flex
        );
    });

    auto screen = App::Fullscreen();
    screen.Loop(main_renderer);
}