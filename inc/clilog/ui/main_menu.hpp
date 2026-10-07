/**
 * 
 * @brief This header defines the MainMenu starting screen.
 * @author Jacob Petersen
 * 
 * Keep it simple, stupid.
 */

#pragma once

#include "ftxui/component/component.hpp"


namespace clilog {

/*
    @brief UI component for the main menu. Extends `ftxui::ComponentBase`. 
*/
class MainMenu : public ftxui::ComponentBase {

    private:
    ftxui::Component menu_;
    std::vector<std::string> entries_ = {
        "Open last logbook",
        "Open logbook",
        "Create new logbook",
        "Settings",
        "Exit"
    };
    int selected_ = 0;

    public:
    MainMenu();
    ftxui::Element OnRender() override;

};

ftxui::Element generate_ascii_title();

}