#include "../Book/Book.hpp"
#include <iostream>

namespace BookManager
{
    int Book::next_book_id = 0;

    Book::Book() : book_id(++next_book_id) {}
    Book::Book(const std::string &title, const std::string &author, const std::string &publication_year)
        : book_id(++next_book_id), title(title), author(author), publication_year(publication_year) {}

    id getId(void) const { return this->id; }
    std::string Book::getTitle(void) const { return this->title; }
    std::string Book::getAuthor(void) const { return this->author; }
    std::string Book::getPublicationYear(void) const { return this->publication_year; }

    void Book::setTitle(const std::string &title) { this->title = title; }
    void Book::setAuthor(const std::string &author) { this->author = author; }
    void Book::setPulibcationYear(const std::string &publication_year) { this->publication_year = publication_year; }

    ~Book::Book() {}

    std::string FinctionBook::getGenre(void) const { return this->genre; }

    void FinctionBook::setGenre(const std::string &genre) { this->genre = genre; }

    void FictionBook::displayInfo() const
    {
        std::cout << "[Fiction] ID: " << getId()
                  << " | Title: " << getTitle()
                  << " | Author: " << getAuthor()
                  << " | Publication Year: " << getPublicationYear()
                  << " | Genre: " << genre << "\n";
    }

    std::string NonFinctionBook::getTopic(void) const { return this->topic; }

    void NonFinctionBook::setTopic(const std::string &topic) { this->topic = topic; }

    void NonFinctionBook::displayInfo() const override
    {
        std::cout << "[Non Finction] ID: " << getId()
                  << " | Title: " << getTitle()
                  << " | Author: " << getAuthor()
                  << " | Publication Year: " << getPublicationYear()
                  << " | Topic: " << topic << "\n";
    }

} // namespace BookManager