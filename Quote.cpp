#include "Quote.hpp"

Quote::Quote() {
    m_Author = "Undefined";
    m_Quote = "Undefined";
}

Quote::Quote(std::string author, std::string quote) {
    m_Author = author;
    m_Quote = quote;
}

std::string Quote::GetAuthor() {
    return m_Author;
}

std::string Quote::GetQuote() {
    return m_Quote;
}

void Quote::SetAuthor(std::string a) {
    if (a.size() < 1) return;
    m_Author = a;
}

void Quote::SetQuote(std::string q) {
    if (q.size() < 1) return;
    m_Quote = q;
}

