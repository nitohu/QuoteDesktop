#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainWindow : public wxFrame {
public:
    MainWindow();

private:
    void OnNewQuote(wxCommandEvent &evt);
    void OnExit(wxCommandEvent &evt);
    void OnAbout(wxCommandEvent &evt);
};

enum {
    ID_NewQuote = 1
};

