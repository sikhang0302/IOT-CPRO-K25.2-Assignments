#include "../Book/Book.hpp"
#include "../Library/Library.hpp"
#include <iostream>
#include <string>

int main(void)
{
    BookManager::Library lib;
    std::string choice_str;
    int choice = -1;
    do
    {
        size_t pos;

        std::cout << "===== Library Menu =====\n";
        std::cout << "1. Add New Book\n";
        std::cout << "2. Search Book\n";
        std::cout << "3. Add Borrow Book Request\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Display All Books\n";
        std::cout << "6. Process Borrow Book Requests\n";
        std::cout << "7. Show Waiting List\n";
        std::cout << "8. Show Last Completed Transaction\n";
        std::cout << "9. Show All Completed Transactions\n";
        std::cout << "10. Show Book Records\n";
        std::cout << "0. Exit\n";
        std::cout << ">> Select: ";
        std::getline(std::cin, choice_str);

        try
        {
            choice = std::stoi(choice_str, &pos);
            if (pos < choice_str.size())
            {
                throw std::invalid_argument("");
            }

            switch (choice)
            {
            case 1:
            {
                std::string title;
                std::string author;
                std::string publication_year_str;
                std::string type_str;
                int type;
                int publication_year;

                std::cout << "Enter type (1. Fiction or 2. Non Fiction): ";
                std::getline(std::cin, type_str);

                try
                {
                    type = std::stoi(type_str, &pos);

                    if (pos < type_str.size())
                    {
                        throw std::invalid_argument("");
                    }

                    if (type != 1 && type != 2)
                    {
                        throw std::out_of_range("");
                    }

                    std::cout << "Enter title: ";
                    std::getline(std::cin, title);
                    std::cout << "Enter author: ";
                    std::getline(std::cin, author);
                    std::cout << "Enter publication year: ";
                    std::getline(std::cin, publication_year_str);
                    try
                    {
                        publication_year = std::stoi(publication_year_str, &pos);
                        if (pos < publication_year_str.size())
                        {
                            throw std::invalid_argument("");
                        }
                        if (publication_year <= 0)
                        {
                            throw std::out_of_range("");
                        }

                        if (type == 1)
                        {
                            std::string genre;
                            std::cout << "Enter genre: ";
                            std::getline(std::cin, genre);
                            lib.addBook(new BookManager::FictionBook(title, author, publication_year, genre));
                        }
                        else
                        {
                            std::string topic;
                            std::cout << "Enter topic: ";
                            std::getline(std::cin, topic);
                            lib.addBook(new BookManager::NonFictionBook(title, author, publication_year, topic));
                        }
                    }
                    catch (const std::invalid_argument &e)
                    {
                        std::cerr << "Publication year must be a number.\n";
                    }
                    catch (const std::out_of_range &e)
                    {
                        std::cerr << "Publication year must be greater than 0.\n";
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << "Invalid type of book.\n";
                }
                catch (const std::out_of_range &e)
                {
                    std::cerr << "Invalid choice! Must be 1 or 2.\n";
                }

                break;
            }
            case 2:
            {
                std::string title_to_search;
                std::cout << "Enter title to search: ";
                std::getline(std::cin, title_to_search);
                lib.searchBook(title_to_search);
                break;
            }
            case 3:
            {
                std::string title_to_borrow;
                std::cout << "Enter title to borrow: ";
                std::getline(std::cin, title_to_borrow);
                lib.borrowBook(title_to_borrow);
                break;
            }
            case 4:
            {
                std::string title_to_return;
                std::cout << "Enter title to return: ";
                std::getline(std::cin, title_to_return);
                lib.returnBook(title_to_return);
                break;
            }
            case 5:
                lib.displayAllBooks();
                break;
            case 6:
                lib.processRequests();
                break;
            case 7:
                lib.showWaitingList();
                break;
            case 8:
                lib.showLastTransaction();
                break;
            case 9:
                lib.showCompletedTransactions();
                break;
            case 10:
                lib.showBookRecords();
                break;
            case 0:
                std::cout << "Exiting the program...\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Choice must be a number.\n";
            choice = -1;
        }

        std::cout << "\n";
    } while (choice != 0);

    return 0;
}