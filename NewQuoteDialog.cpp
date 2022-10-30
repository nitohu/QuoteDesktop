#include "NewQuoteDialog.hpp"

#include <iostream>

NewQuoteDialog::NewQuoteDialog(wxWindow *parent)
    : wxDialog(parent, wxID_ANY, "Create new quote") {
        wxBoxSizer *top = new wxBoxSizer(wxVERTICAL);
        wxBoxSizer *btn_bar = new wxBoxSizer(wxHORIZONTAL);
        
       m_quoteTxt = new wxTextCtrl(this, wxID_ANY);
       m_authorTxt = new wxTextCtrl(this, wxID_ANY);

       m_createBtn = new wxButton(this, ID_CreateQuote, "Create");
       m_discardBtn = new wxButton(this, wxID_CLOSE, "Discard");

       btn_bar->Add(m_createBtn);
       btn_bar->Add(m_discardBtn);

       top->Add(m_quoteTxt);
       top->Add(m_authorTxt);
       top->Add(btn_bar);

       SetSizerAndFit(top);
       SetEscapeId(wxID_CLOSE);

       Bind(wxEVT_BUTTON, &NewQuoteDialog::OnCreateQuote, this, ID_CreateQuote);
       m_discardBtn->Bind(wxEVT_BUTTON, &NewQuoteDialog::OnDiscardQuote, this);
};

void NewQuoteDialog::OnCreateQuote(wxCommandEvent &evt) {
    std::cout << "New Quote created" << std::endl;
    this->EndModal(wxID_OK);
}

void NewQuoteDialog::OnDiscardQuote(wxCommandEvent &evt) {
    std::cout << "Close dialog" << std::endl;
    this->EndModal(wxID_ANY);
}

wxString NewQuoteDialog::GetAuthor() const {
    return m_authorTxt->GetValue();
}

wxString NewQuoteDialog::GetQuote() const {
    return m_quoteTxt->GetValue();
}

