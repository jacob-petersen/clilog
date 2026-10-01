# Keep it simple, stupid.

cmake_minimum_required(VERSION 3.14)
project(clilog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui.git
    GIT_TAG        v7.0.3
)
FetchContent_MakeAvailable(ftxui)

add_executable(clilog
    main.cpp
)

target_link_libraries(clilog PRIVATE
   ftxui::screen
   ftxui::dom
   ftxui::component
)