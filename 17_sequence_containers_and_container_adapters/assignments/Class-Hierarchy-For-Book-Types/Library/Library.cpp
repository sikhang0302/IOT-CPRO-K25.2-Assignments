#include "../Library/Library.hpp"
#include <iostream>
#include <algorithm> // Required for std::transform
#include <cctype>    // Required for ::tolower

static std::string toLower(const std::string &input_str)
{
    std::string lower_str = input_str;
    std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(), ::tolower);
    return lower_str;
}

namespace BookManager
{
    Library::Library() {}

    void Library::addBook(Book *book)
    {
        library_books.emplace_back(book);
        std::cout << "Successfully added a book!\n";
        BookRecord *book_record = searchRecord(book->getTitle());
        if (book_record)
        {
            (book_record->number_of_copies)++;
            std::cout << "Successfully add a copy of book " << book->getTitle() << "\n";
        }
        else
        {
            BookRecord tmp_record;
            tmp_record.book = book;
            tmp_record.number_of_copies = 1;
            book_records.push_back(tmp_record);
            std::cout << "Successfully added a book record!\n";
        }
    }

    void Library::displayAllBooks(void) const
    {
        if (library_books.empty())
        {
            std::cout << "List of books is currently empty!\n";
        }
        else
        {
            int count_books = 0;
            for (const auto &b : library_books)
            {
                count_books++;
                std::cout << "[Book " << count_books << "]\n";
                b->displayInfo();
            }
        }
    }

    Book *Library::searchBook(std::string title) const
    {
        if (library_books.empty())
        {
            std::cout << "List of books is currently empty!\n";
        }
        else
        {
            int count_books = 0;
            Book *temp_book = nullptr;
            for (const auto &b : library_books)
            {
                if (toLower(b->getTitle()) == toLower(title))
                {
                    count_books++;
                    if (count_books == 1)
                    {
                        temp_book = b;
                    }
                }
            }

            if (count_books != 0)
            {
                std::cout << "Found " << count_books << " in the library.\n";
                return temp_book;
            }
            else
            {

                std::cout << "No book with title: " << title << " found.\n";
            }
        }
        return nullptr;
    }

    Book *Library::searchBook(std::string title, int &num_of_books) const
    {
        if (library_books.empty())
        {
            std::cout << "List of books is currently empty!\n";
        }
        else
        {
            num_of_books = 0;
            Book *temp_book = nullptr;
            for (const auto &b : library_books)
            {
                if (toLower(b->getTitle()) == toLower(title))
                {
                    num_of_books++;
                    if (num_of_books == 1)
                    {
                        temp_book = b;
                    }
                }
            }

            if (num_of_books != 0)
            {
                std::cout << "Found " << num_of_books << " in the library.\n";
                return temp_book;
            }
            else
            {

                std::cout << "No book with title: " << title << " found.\n";
            }
        }
        return nullptr;
    }

    BookRecord *Library::searchRecord(std::string title)
    {
        for (auto &r : book_records)
        {
            if (toLower(r.book->getTitle()) == toLower(title))
            {
                return &r;
            }
        }
        return nullptr;
    }

    void Library::borrowBook(std::string title)
    {
        if (searchBook(title))
        {
            borrow_requests.push(title);
            std::cout << "Borrow request for book with title: " << title << " added.\n";
        }
    }

    void Library::returnBook(std::string title)
    {
        int num_of_books;
        if (searchBook(title, num_of_books))
        {
            BookRecord *book_record = searchRecord(title);
            if (book_record->number_of_copies < num_of_books)
            {
                completed_transactions.push("Returned book: " + title);
                std::cout << "Book with title: " << title << " returned.\n";
                std::cout << "Copy of book with title: " << title << " returned.\n";

                // Check waiting list
                int request_index = searchWaitingList(title);
                if (request_index != -1)
                {
                    waiting_list.erase(waiting_list.begin() + request_index);
                    completed_transactions.push("Borrowed book (from waiting list): " + title);
                    std::cout << "Book: " << title
                              << " is immediately borrowed by Request "
                              << (request_index + 1)
                              << " in waiting list.\n";
                }
                else
                {
                    (book_record->number_of_copies)++;
                }
            }
            else
            {
                std::cout << "This book is not owned by library.\n";
            }
        }
    }

    void Library::processRequests(void)
    {
        if (borrow_requests.empty())
        {
            std::cout << "List of borrrow requests is currently empty!\n";
        }
        else
        {
            while (!(borrow_requests.empty()))
            {
                std::string title = borrow_requests.front();
                borrow_requests.pop();

                BookRecord *book_record = searchRecord(title);
                if (book_record->number_of_copies == 0)
                {
                    std::cout << "Book with title: " << title
                              << " is currently busy! Added request to waiting list\n";
                    waiting_list.push_back(title);
                }
                else
                {
                    (book_record->number_of_copies)--;
                    completed_transactions.push("Borrowed book: " + title);
                    std::cout << "Processed borrow request for book with title: "
                              << title << "\n";
                }
            }
        }
    }

    void Library::showLastTransaction(void) const
    {
        if (completed_transactions.empty())
        {
            std::cout << "List of completed transaction is current empty!\n";
        }
        else
        {
            std::cout << "Last completed transaction: " << completed_transactions.top() << "\n";
        }
    }

    void Library::showCompletedTransactions(void) const
    {
        if (completed_transactions.empty())
        {
            std::cout << "List of completed transaction is current empty!\n";
        }
        else
        {
            std::stack<std::string> temp_transactions = completed_transactions;
            std::cout << "List of completed transactions:\n";
            while (!(temp_transactions.empty()))
            {
                std::cout << temp_transactions.top() << "\n";
                temp_transactions.pop();
            }
        }
    }

    int Library::searchWaitingList(std::string title) const
    {
        int index = 0;
        for (const auto &w : waiting_list)
        {
            if (toLower(w) == toLower(title))
            {
                return index;
            }
            index++;
        }
        return -1;
    }

    void Library::showWaitingList(void) const
    {
        if (waiting_list.empty())
        {
            std::cout << "Waiting list is currently empty!\n";
        }
        else
        {
            std::cout << "List of waiting requests:\n";
            int count_requests = 0;
            for (const auto &w : waiting_list)
            {
                count_requests++;
                std::cout << "[Request " << count_requests << "]: " << w << "\n";
            }
        }
    }

    void Library::showBookRecords(void) const
    {
        if (book_records.empty())
        {
            std::cout << "List of records is currently empty!\n";
        }
        else
        {
            std::cout << "List of book records:\n";
            int count_records = 0;
            for (const auto &r : book_records)
            {
                count_records++;
                std::cout << "[Record " << count_records << "] Title: " << r.book->getTitle()
                          << " | Number of Copies: " << r.number_of_copies << "\n";
            }
        }
    }

    Library::~Library()
    {
        for (const auto &b : library_books)
        {
            delete b;
        }
    }
} // namespace BookManager