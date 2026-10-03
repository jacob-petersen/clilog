// Keep it simple, stupid

#include <string>

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"

int main() {
    
    using namespace ftxui;

    std::string first_name;
    std::string last_name;
    std::string password;
    std::string phone_number;

    Component input_first_name = Input(&first_name, "first name");
    Component input_last_name = Input(&last_name, "last name");

    auto component_tree = Container::Vertical({
        input_first_name,
        input_last_name
    });

    auto screen = App::TerminalOutput();
    screen.Loop(component_tree);

}