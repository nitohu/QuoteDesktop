#include "MainWindow.hpp"

MainWindow::MainWindow() : wxFrame (nullptr, wxID_ANY, "Quotes") {
    // Create main quote menu
    wxMenu *menuQuotes = new wxMenu;
    menuQuotes->Append(ID_NewQuote, "&New Quote\tCtrl-N", "Create a new quote");
    menuQuotes->AppendSeparator();
    menuQuotes->Append(wxID_EXIT);

    // Create help menu
    wxMenu *menuAbout = new wxMenu;
    menuAbout->Append(wxID_ABOUT);

    // Create menu & status bar
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuQuotes);
    menuBar->Append(menuAbout);

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Some random introduction quote...");

    // Create button bindings
    Bind(wxEVT_MENU, &MainWindow::OnNewQuote, this, ID_NewQuote);
    Bind(wxEVT_MENU, &MainWindow::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);
}

void MainWindow::OnNewQuote() {
    wxLogMessage("Create new quote");
}

void MainWindow::OnAbout() {
    wxMessageBox("This is a small app for storing quotes", "About Quotes", wxOK | wxICON_INFORMATION);
}

void MainWindow::OnExit() {
    Close(true);
}

