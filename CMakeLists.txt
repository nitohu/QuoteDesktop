cmake_minimum_required(3.18)
project(quotes)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/wxWidgets)
add_executable(QuoteApp main.cpp MainWindow.cpp QuoteApp.cpp)
target_link_libraries(QuoteApp wx::core wx::base)

