#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>

namespace BookManager
{
    class Book
    {
    private:
        std::string title;
        std::string author;
        std::string publication_year;
        static int next_book_id;
        int book_id;

    public:
        Book();
        Book(const std::string &title, const std::string &author, const std::string &publication_year);

        virtual id getId(void) const;
        virtual std::string getTitle(void) const;
        virtual std::string getAuthor(void) const;
        virtual std::string getPublicationYear(void) const;

        void setTitle(const std::string &title);
        void setAuthor(const std::string &author);
        void setPulibcationYear(const std::string &publication_year);

        virtual void displayInfo() const = 0;

        virtual ~Book();
    };

    class FictionBook : public Book
    {
    private:
        std::string genre;

    public:
        std::string getGenre(void) const;

        void setGenre(const std::string &genre);

        void displayInfo() const override;
    };

    class NonFictionBook : public Book
    {
    private:
        std::string topic;

    public:
        std::string getTopic(void) const;

        void setTopic(const std::string &topic);

        void displayInfo() const override;
    };
} // namespace BookManager

#endif // !__BOOK_H__