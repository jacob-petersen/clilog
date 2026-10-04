/*
    Keep it simple, stupid.
*/

#pragma once

#include "ftxui/component/component.hpp"

namespace clilog {

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