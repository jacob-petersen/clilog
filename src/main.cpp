#include <string>
#include <vector>

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"

#include "ui/main_menu.hpp"

int main() {

    using namespace ftxui;

    auto main_menu = ftxui::Make<clilog::MainMenu>();

    auto screen = App::Fullscreen();
    screen.Loop(main_menu);
}