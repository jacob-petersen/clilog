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
    auto menu_renderer = Renderer(menu, [&]{
        return menu->Render() | size(HEIGHT, EQUAL, 4) | size(WIDTH, EQUAL, 30) | border | center;
    });

    auto screen = App::Fullscreen();
    screen.Loop(menu_renderer);
}