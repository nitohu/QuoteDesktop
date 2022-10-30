#include <string>

class Quote {
public:
    Quote();
    Quote(std::string author, std::string quote);

    std::string GetAuthor();
    std::string GetQuote();

    void SetAuthor(std::string);
    void SetQuote(std::string);

private:
    std::string m_Author;
    std::string m_Quote;

};

