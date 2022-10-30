cmake_minimum_required(VERSION 3.18)
project(quotes)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/wxWidgets)
add_executable(QuoteApp NewQuoteDialog.cpp QuoteList.cpp QuoteApp.cpp MainWindow.cpp main.cpp)
target_link_libraries(QuoteApp wx::core wx::base wx::net)

set(wxBUILD_SHARED OFF)

