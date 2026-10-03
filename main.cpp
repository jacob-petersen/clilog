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
        "Exit"
    };
    int selected = 0;

    auto menu = Menu(&menu_items, &selected);
    
    auto screen = App::Fullscreen();
    screen.Loop(menu);
}