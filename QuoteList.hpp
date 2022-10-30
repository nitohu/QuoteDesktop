#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/listctrl.h>
#endif

class QuoteList : public wxListCtrl {
public:
    QuoteList(wxWindow *parent,
                const wxWindowID id,
                const wxPoint &pos,
                const wxSize &size,
                long style) : wxListCtrl(parent, id, pos, size, style) {
                    wxListItem qCol;
                    qCol.SetId(0);
                    qCol.SetText("Quote");
                    qCol.SetWidth(500);
                    this->InsertColumn(0, qCol);

                    wxListItem aCol;
                    aCol.SetId(1);
                    aCol.SetText("Author/Source");
                    aCol.SetWidth(200);
                    this->InsertColumn(1, aCol);
                }
};

