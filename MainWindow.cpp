#include "MainWindow.hpp"
#include "NewQuoteDialog.hpp"

MainWindow::MainWindow() : wxFrame (nullptr, wxID_ANY, "Quotes") {
    // Create main quote menu
    wxMenu *menuQuotes = new wxMenu;
    menuQuotes->Append(ID_NewQuote, "&New Quote\tCtrl-N", "Create a new quote");
    menuQuotes->AppendSeparator();
    menuQuotes->Append(ID_OpenFile, "&Open File\tCtrl-O", "Open an existing quote storage file");
    menuQuotes->AppendSeparator();
    menuQuotes->Append(wxID_EXIT);

    // Create help menu
    wxMenu *menuAbout = new wxMenu;
    menuAbout->Append(wxID_ABOUT);

    // Create menu bar
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuQuotes, "&Quotes");
    menuBar->Append(menuAbout, "&About");

    SetMenuBar(menuBar);

    m_panel = new wxPanel(this, wxID_ANY);
    m_quoteList = new QuoteList(m_panel,
                                    wxID_ANY,
                                    wxDefaultPosition,
                                    wxDefaultSize,
                                    wxLC_REPORT | wxBORDER_THEME | wxLC_EDIT_LABELS); 

    // Create status bar
    CreateStatusBar();
    SetStatusText("It always seems impossible until it's done.");

    // Create list view
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    
    sizer->Add(m_quoteList, wxSizerFlags(2).Expand().Border());

    m_panel->SetSizer(sizer);

    SetClientSize(m_panel->GetBestSize());

    // Create button bindings
    Bind(wxEVT_MENU, &MainWindow::OnNewQuote, this, ID_NewQuote);
    Bind(wxEVT_MENU, &MainWindow::OnOpenFile, this, ID_OpenFile);
    Bind(wxEVT_MENU, &MainWindow::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);
}

void MainWindow::OnNewQuote(wxCommandEvent &evt) {
    NewQuoteDialog diag(this);

    if (diag.ShowModal() == wxID_OK) {
        m_quoteList->AddListItem(diag.GetAuthor(), diag.GetQuote());
    }
}

void MainWindow::OnOpenFile(wxCommandEvent &evt) {
    wxFileDialog openFileDialog(this, "Open Quote Storage", "", "", "JSON (*.json)|*.json", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL) return;
    
    m_quoteList->ClearList();
    m_quoteList->LoadFile(openFileDialog.GetPath());
}

void MainWindow::OnAbout(wxCommandEvent &evt) {
    wxMessageBox("This is a small app for storing quotes", "About Quotes", wxOK | wxICON_INFORMATION);
}

void MainWindow::OnExit(wxCommandEvent &evt) {
    Close(true);
}

