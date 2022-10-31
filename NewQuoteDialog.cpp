#include "NewQuoteDialog.hpp"

#include <iostream>

NewQuoteDialog::NewQuoteDialog(wxWindow *parent)
    : wxDialog(parent, wxID_ANY, "Create new quote") {
        wxFlexGridSizer *top = new wxFlexGridSizer(2, 3, 3);
        
        wxStaticText *quoteLabel = new wxStaticText(this, wxID_ANY, "Quote");
        m_quoteTxt = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(400, -1));
        top->Add(quoteLabel);
        top->Add(m_quoteTxt);

        wxStaticText *authorLabel = new wxStaticText(this, wxID_ANY, "Author / Source");
        m_authorTxt = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(400, -1));
        top->Add(authorLabel);
        top->Add(m_authorTxt);

        m_createBtn = new wxButton(this, ID_CreateQuote, "Create");
        m_discardBtn = new wxButton(this, wxID_CLOSE, "Discard");
        top->Add(m_createBtn);
        top->Add(m_discardBtn);

        SetSizerAndFit(top);
        SetEscapeId(wxID_CLOSE);

        Bind(wxEVT_BUTTON, &NewQuoteDialog::OnCreateQuote, this, ID_CreateQuote);
        m_discardBtn->Bind(wxEVT_BUTTON, &NewQuoteDialog::OnDiscardQuote, this);
};

void NewQuoteDialog::OnCreateQuote(wxCommandEvent &evt) {
    this->EndModal(wxID_OK);
}

void NewQuoteDialog::OnDiscardQuote(wxCommandEvent &evt) {
    this->EndModal(wxID_ANY);
}

wxString NewQuoteDialog::GetAuthor() const {
    return m_authorTxt->GetValue();
}

wxString NewQuoteDialog::GetQuote() const {
    return m_quoteTxt->GetValue();
}

