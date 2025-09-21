#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include "../Book/Book.hpp"
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>

namespace BookManager
{
    struct BookRecord
    {
    public:
        Book *book;
        int number_of_copies;
    };

    class Library
    {
    private:
        std::vector<Book *> library_books;
        std::vector<BookRecord> book_records;
        std::stack<std::string> completed_transactions;
        std::queue<std::string> borrow_requests;
        std::deque<std::string> waiting_list;

    public:
        Library();

        void addBook(Book *book);
        void displayAllBooks(void) const;
        Book *searchBook(std::string title) const;
        Book *searchBook(std::string title, int &num_of_books) const;
        BookRecord *searchRecord(std::string title);
        void displayBookRecords(void) const;
        void borrowBook(std::string title);
        void returnBook(std::string title);
        void processRequests(void);
        void showLastTransaction(void) const;
        void showCompletedTransactions(void) const;
        int searchWaitingList(std::string title) const;
        void showWaitingList(void) const;
        void showBookRecords(void) const;

        ~Library();
    };
} // namespace BookManager

#endif // !__LIBRARY_H__