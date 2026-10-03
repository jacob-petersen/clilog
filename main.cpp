// Keep it simple, stupid

#include <string>

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/dom/elements.hpp"

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

    // Password input, need to specify to obscure input
    InputOption password_options;
    password_options.password = true;
    Component input_password = Input(&password, "password", password_options);

    // Phone number input
    InputOption phone_number_options;
    phone_number_options.multiline = false;
    Component input_phone_number = Input(&phone_number, "phone number", phone_number_options);

    // We want to limit the phone number input to only numerical characters. We use a CatchEvent
    // Make sure the event is a numerical character
    input_phone_number |= CatchEvent([&](Event event) {
        return event.is_character() && !std::isdigit(event.character()[0]);
    });
    // Make sure the phone number field is no longer than 10 characters (digits)
    input_phone_number |= CatchEvent([&](Event event) {
        return event.is_character() && phone_number.size() >= 10;
    });

    // Component tree that logically lays out these things vertically (for tab navigation etc)
    auto component_tree = Container::Vertical({
        input_first_name,
        input_last_name,
        input_password,
        input_phone_number
    });

    auto tree_renderer = Renderer(component_tree, [&]{
        return vbox({
            hbox(text("First name: "), input_first_name->Render()),
            hbox(text("Last name: "), input_last_name->Render()),
            hbox(text("Password: "), input_password->Render()),
            hbox(text("Phone number: "), input_phone_number->Render()),
            separator(),
            text("Hello " + first_name + " " + last_name),
            text("Your password is " + password),
            text("Your phone number is " + phone_number)
        }) | border;
    });

    auto screen = App::TerminalOutput();
    screen.Loop(tree_renderer);

}