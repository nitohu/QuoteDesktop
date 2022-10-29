#include "QuoteApp.hpp"
#include "MainWindow.hpp"

bool QuoteApp::OnInit() {
    MainWindow *win = new MainWindow();
    win->Show(true);
    return true;
}

