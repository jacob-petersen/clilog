/*
    Keep it simple, stupid.
*/

#include <string>
#include <vector>
#include <thread>
#include <chrono>

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"

#include "clilog/log_store.hpp"
#include "clilog/ui/main_menu.hpp"
#include "clilog/ui/log_input.hpp"
#include "clilog/ui/logging_screen.hpp"

int main() {

    using namespace ftxui;

    // running bool - used to tell threads to stop
    bool running = true;

    clilog::LogStore log_store;
    log_store.DEBUG_generate_sample_log_entries(10);

    auto main_menu = ftxui::Make<clilog::MainMenu>();
    auto logging_screen = ftxui::Make<clilog::LoggingScreen>(log_store);
    auto screen = App::Fullscreen();

    // Thread that forces a redraw every second
    std::thread time_ticker([&] {
        while (running) {
            screen.PostEvent(Event::Custom);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    screen.Loop(logging_screen);
    
    // When screen.Loop exits, the program is shutting down
    running = false;
    time_ticker.join();
}