#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/listctrl.h>
#endif

class QuoteList : public wxListCtrl {
public:
    QuoteList(wxWindow *parent, const wxWindowID id, const wxPoint &pos, const wxSize &size, long style);

    void AddListItem(wxString author, wxString quote);

private:
    static int rec_counter;
};

