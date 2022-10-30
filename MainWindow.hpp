#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "QuoteList.hpp"

/**
* TODO: Store/Save current list of todos
* TODO: Delete elements from the list
* FIXME: Texts with "Umlaut" (äüöß) are not loaded
*/

class MainWindow : public wxFrame {
public:
    MainWindow();

    wxPanel *m_panel;
    QuoteList *m_quoteList;

private:
    void OnNewQuote(wxCommandEvent &evt);
    void OnOpenFile(wxCommandEvent &evt);
    void OnSave(wxCommandEvent &evt);
    void OnSaveAs(wxCommandEvent &evt);
    void OnExit(wxCommandEvent &evt);
    void OnAbout(wxCommandEvent &evt);

    void InitQuoteList();
};

enum {
    ID_NewQuote = 1,
    ID_OpenFile,
    ID_SaveFile,
    ID_SaveFileAs
};

