#include <string>
#include <vector>
#include <thread>
#include <chrono>

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"

#include "clilog/ui/main_menu.hpp"

int main() {

    using namespace ftxui;

    // running bool - used to tell threads to stop
    bool running = true;

    auto main_menu = ftxui::Make<clilog::MainMenu>();
    auto screen = App::Fullscreen();

    // Thread that forces a redraw every second
    std::thread time_ticker([&] {
        while (running) {
            screen.PostEvent(Event::Custom);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    screen.Loop(main_menu);
    
    // When screen.Loop exits, the program is shutting down
    running = false;
    time_ticker.join();
}