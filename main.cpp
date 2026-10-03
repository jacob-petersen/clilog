// Keep it simple, stupid

#include <string>

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"

int main() {
    
    using namespace ftxui;

    // Strings that will hold data
    std::string first_name;
    std::string last_name;
    std::string password;
    std::string phone_number;

    // Basic text inputs
    Component input_first_name = Input(&first_name, "first name");
    Component input_last_name = Input(&last_name, "last name");

    // Component tree that logically lays out these things vertically (for tab navigation etc)
    auto component_tree = Container::Vertical({
        input_first_name,
        input_last_name
    });

    auto screen = App::TerminalOutput();
    screen.Loop(component_tree);

}