#include <wx/wxprec.h>
#include "Quote.hpp"

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/textfile.h>
#endif

class QuoteList : public wxListCtrl {
public:
    QuoteList(wxWindow *parent, const wxWindowID id, const wxPoint &pos, const wxSize &size, long style);

    void AddListItem(wxString author, wxString quote);
    void DeleteSelectedRecord();
    void ClearList();
    void LoadFile(wxString file_path);
    void WriteFile();
    void WriteFile(wxString file_path);

private:
    static int m_recCounter;
    static int m_maxArrSize;

    wxString m_filePath = "/home/nitohu/Development/cpp/quotes/example-data.json";

    void processFile(wxTextFile&, wxString*);
};

