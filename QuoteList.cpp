#include "QuoteList.hpp"

int QuoteList::rec_counter = 0;

QuoteList::QuoteList(wxWindow *parent,  const wxWindowID id, const wxPoint &pos, const wxSize &size, long style)
    : wxListCtrl(parent, id, pos, size, style) {
        wxListItem col;
        col.SetId(0);
        col.SetText("Quote");
        col.SetWidth(500);
        this->InsertColumn(0, col);

        col.SetId(1);
        col.SetText("Author / Source");
        col.SetWidth(200);
        this->InsertColumn(1, col);
}

void QuoteList::AddListItem(wxString author, wxString quote) {
    long n = this->InsertItem(rec_counter, author);
    this->SetItem(n, 1, quote);
    rec_counter++;
};

