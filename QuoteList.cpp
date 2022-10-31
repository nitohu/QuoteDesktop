#include "QuoteList.hpp"
#include <ArduinoJson.h>

#include <iostream>
#include <fstream>

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

        LoadFile(m_filePath); 
}

void QuoteList::AddListItem(wxString author, wxString quote) {
    long n = this->InsertItem(m_recCounter, quote);
    this->SetItem(n, 1, author);
    m_recCounter++;
}

void QuoteList::DeleteSelectedRecord() {
    long item = -1;
    // Find currently selected item, currently works only for single selections, for multiselections it'll only delete the first item
    item = this->GetNextItem(item, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED);

    // If item still wasn't found for whatever reason, quote function execution
    if (item == wxNOT_FOUND) {
        std::cout << "WARN: No item could be found" << std::endl;
        return;
    }

    // TODO: Maybe show messageboxes instead of printing warnings to the console
    if (!this->DeleteItem(item)) {
        std::cout << "WARN: Item " << item << " could not be deleted." << std::endl;
    }
}

void QuoteList::ClearList() {
    m_recCounter = 0;
    DeleteAllItems();
}

void QuoteList::LoadFile(wxString file_path) {
        m_filePath = file_path;

        // NOTE: Optimization potential, wxTextFile is only fine for small files (<1mb)
        // since it loads the whole file content into memory
        wxTextFile quoteFile;
        quoteFile.Open(file_path);

        if (!quoteFile.IsOpened()) {
            std::cout << "File " << file_path << " could not be loaded." << std::endl;
            return;
        }
    
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

        // Add items from file to list
        for (int i = 0; i < doc.size(); i++) {
            Quote quote(doc[i]["author"], doc[i]["quote"]);
            AddListItem(wxString::FromUTF8(quote.GetAuthor()), wxString::FromUTF8(quote.GetQuote()));
        }

        // free memory for fileContent
        delete fileContent;
}

void QuoteList::WriteFile() {
    WriteFile(m_filePath);
}

void QuoteList::WriteFile(wxString file_path) {
    m_filePath = file_path;

    std::ofstream quoteFile;
    quoteFile.open(m_filePath.utf8_string(), std::ofstream::out | std::ofstream::trunc);
    if (!quoteFile.is_open()) {
        std::cout << "Error while opening file " << m_filePath << std::endl;
        quoteFile.close();
        return;
    }

    const int capacity = JSON_ARRAY_SIZE(m_maxArrSize) + m_maxArrSize * JSON_OBJECT_SIZE(2);
    DynamicJsonDocument doc(capacity);
    JsonArray root = doc.to<JsonArray>();

    for (int i = 0; i < GetItemCount(); i++) {
        wxListItem item;
        JsonObject obj = root.createNestedObject();

        item.SetId(i);
        GetItem(item);
        std::string quote = item.GetText().utf8_string();
        obj["quote"] = quote;

        item.SetColumn(1);
        GetItem(item);
        std::string author = item.GetText().utf8_string();
        obj["author"] = author;
    }

    serializeJson(root, quoteFile);

    quoteFile.close();
}

void QuoteList::processFile(wxTextFile &file, wxString *fileContent) {
    fileContent->Append(file.GetFirstLine());
    while (!file.Eof()) {
        fileContent->Append(file.GetNextLine());
    }
}

