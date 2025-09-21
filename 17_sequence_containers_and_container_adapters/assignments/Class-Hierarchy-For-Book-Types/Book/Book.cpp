#include "../Book/Book.hpp"
#include <iostream>

namespace BookManager
{
    int Book::next_book_id = 0;

    Book::Book() : book_id(++next_book_id) {}
    Book::Book(const std::string &title, const std::string &author, int publication_year)
        : book_id(++next_book_id), title(title), author(author), publication_year(publication_year) {}

    int Book::getId(void) const { return this->book_id; }
    std::string Book::getTitle(void) const { return this->title; }
    std::string Book::getAuthor(void) const { return this->author; }
    int Book::getPublicationYear(void) const { return this->publication_year; }

    void Book::setTitle(const std::string &title) { this->title = title; }
    void Book::setAuthor(const std::string &author) { this->author = author; }
    void Book::setPulibcationYear(int publication_year) { this->publication_year = publication_year; }

    Book::~Book() {}

    FictionBook::FictionBook(const std::string &title, const std::string &author,
                             int publication_year, const std::string &genre)
        : Book(title, author, publication_year), genre(genre) {}

    std::string FictionBook::getGenre(void) const { return this->genre; }

    void FictionBook::setGenre(const std::string &genre) { this->genre = genre; }

    void FictionBook::displayInfo() const
    {
        std::cout << "[Fiction] ID: " << getId()
                  << " | Title: " << getTitle()
                  << " | Author: " << getAuthor()
                  << " | Publication Year: " << getPublicationYear()
                  << " | Genre: " << genre << "\n";
    }

    NonFictionBook::NonFictionBook(const std::string &title, const std::string &author,
                                   int publication_year, const std::string &topic)
        : Book(title, author, publication_year), topic(topic) {}

    std::string NonFictionBook::getTopic(void) const { return this->topic; }

    void NonFictionBook::setTopic(const std::string &topic) { this->topic = topic; }

    void NonFictionBook::displayInfo() const
    {
        std::cout << "[Non Finction] ID: " << getId()
                  << " | Title: " << getTitle()
                  << " | Author: " << getAuthor()
                  << " | Publication Year: " << getPublicationYear()
                  << " | Topic: " << topic << "\n";
    }

} // namespace BookManager