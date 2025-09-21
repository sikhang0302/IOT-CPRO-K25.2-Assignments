#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>

namespace BookManager
{
    class Book
    {
    private:
        static int next_book_id;
        int book_id;
        std::string title;
        std::string author;
        int publication_year;

    public:
        Book();
        Book(const std::string &title, const std::string &author, int publication_year);

        virtual int getId(void) const;
        virtual std::string getTitle(void) const;
        virtual std::string getAuthor(void) const;
        virtual int getPublicationYear(void) const;

        void setTitle(const std::string &title);
        void setAuthor(const std::string &author);
        void setPulibcationYear(int publication_year);

        virtual void displayInfo() const = 0;

        virtual ~Book();
    };

    class FictionBook : public Book
    {
    private:
        std::string genre;

    public:
        FictionBook(const std::string &title, const std::string &author,
                    int publication_year, const std::string &genre);

        std::string getGenre(void) const;

        void setGenre(const std::string &genre);

        void displayInfo() const override;
    };

    class NonFictionBook : public Book
    {
    private:
        std::string topic;

    public:
        NonFictionBook(const std::string &title, const std::string &author,
                       int publication_year, const std::string &topic);

        std::string getTopic(void) const;

        void setTopic(const std::string &topic);

        void displayInfo() const override;
    };
} // namespace BookManager

#endif // !__BOOK_H__