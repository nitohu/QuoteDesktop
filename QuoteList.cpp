#include "QuoteList.hpp"
#include <ArduinoJson.h>

#include <iostream>

int QuoteList::m_recCounter = 0;
int QuoteList::m_maxArrSize = 50;

QuoteList::QuoteList(wxWindow *parent, const wxWindowID id, const wxPoint &pos, const wxSize &size, long style)
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

        // NOTE: Optimization potential, wxTextFile is only fine for small files (<1mb)
        // since it loads the whole file content into memory
        wxTextFile quoteFile;
        quoteFile.Open(m_filePath);
    
        wxString *fileContent = new wxString;
        processFile(quoteFile, fileContent);

        if (fileContent->IsEmpty()) {
            std::cout << "File " << quoteFile.GetName() << " has no content." << std::endl;
            return;
        }

        // NOTE: Might need some adjustment
        // Currently: 1 Array w/ m_maxArrSize elements
        // In Array, m_maxArrSize objects w/ two elements each
        const int capacity = JSON_ARRAY_SIZE(m_maxArrSize) + m_maxArrSize * JSON_OBJECT_SIZE(2);
        DynamicJsonDocument doc(capacity);
        deserializeJson(doc, fileContent->utf8_string());

        for (int i = 0; i < doc.size(); i++) {
            std::cout << i << ".: " << doc[i]["quote"] << " from " << doc[i]["author"] << std::endl;

            Quote quote(doc[i]["author"], doc[i]["quote"]);
            // FIXME: Currently no quotes w/ äüöß etc. are loaded
            AddListItem(quote.GetAuthor(), quote.GetQuote());
        }

        delete fileContent;
}

void QuoteList::AddListItem(wxString author, wxString quote) {
    long n = this->InsertItem(m_recCounter, quote);
    this->SetItem(n, 1, author);
    m_recCounter++;
}

void QuoteList::processFile(wxTextFile &file, wxString *fileContent) {
    fileContent->Append(file.GetFirstLine());
    while (!file.Eof()) {
        fileContent->Append(file.GetNextLine());
    }
}

