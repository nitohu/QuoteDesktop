#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class NewQuoteDialog : public wxDialog {
public:
    NewQuoteDialog(wxWindow *parent); 

    wxString GetAuthor() const;
    wxString GetQuote() const;

private:
    wxButton *m_createBtn, *m_discardBtn;
    wxTextCtrl *m_quoteTxt, *m_authorTxt;

    void OnCreateQuote(wxCommandEvent &evt);
    void OnDiscardQuote(wxCommandEvent &evt);
};

enum {
    ID_CreateQuote
};

