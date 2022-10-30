#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "QuoteList.hpp"

/**
* TODO: Store/Save current list of todos
* TODO: Load different lists with filedialog
* TODO: Delete elements from the list
*/

class MainWindow : public wxFrame {
public:
    MainWindow();

    wxPanel *m_panel;
    QuoteList *m_quoteList;

private:
    void OnNewQuote(wxCommandEvent &evt);
    void OnExit(wxCommandEvent &evt);
    void OnAbout(wxCommandEvent &evt);

    void InitQuoteList();
};

enum {
    ID_NewQuote = 1,
    ID_QuoteList
};

