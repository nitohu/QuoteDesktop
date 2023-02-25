cmake_minimum_required(VERSION 3.18)
project(quotes)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(SRC_FILES
    Quote.cpp
    NewQuoteDialog.cpp
    QuoteList.cpp
    QuoteApp.cpp
    MainWindow.cpp
    main.cpp)

set(wxBUILD_SHARED OFF)
# set(wxBUILD_PRECOMP OFF)

FetchContent_Declare(
    wxWidgets
    GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
    GIT_TAG v3.2.2.1
    GIT_SHALLOW TRUE
)

FetchContent_GetProperties(wxWidgets)
FetchContent_MakeAvailable(wxWidgets)

add_subdirectory(libs/ArduinoJSON)

if (MSVC)
    add_executable(QuoteApp WIN32 ${SRC_FILES})
else()
    add_executable(QuoteApp ${SRC_FILES})
endif()

if (UNIX)
    target_link_libraries(QuoteApp wxbase wxnet wxcore ArduinoJson X11)
else()
    target_link_libraries(QuoteApp wxbase wxnet wxcore ArduinoJson)
endif()

