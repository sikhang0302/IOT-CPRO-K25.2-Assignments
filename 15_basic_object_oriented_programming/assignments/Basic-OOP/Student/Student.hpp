#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>
#include <vector>

namespace StudentSystem
{
    class Student
    {
    private:
        static int id;
        std::string name;
        float gpa;

        void setNewId(int id);

    public:
        Student();
        Student(std::string name, float gpa);
        ~Student();

        int getId(void) const;
        std::string getName(void) const;
        float getGpa(void) const;

        void setName(const std::string &name);
        void setGpa(float gpa);

        bool operator==(const int studentId);

        void addStudent(const std::string &name, float gpa);
        void showInfo(void) const;
    };

    class StudentList
    {
    private:
        std::vector<Student> studentList;

    public:
        StudentList();
        StudentList(const std::vector<Student> &studentList);
        ~StudentList();

        std::vector<Student> getStudentList(void) const;

        void setStudentList(std::vector<Student> &studentList);

        Student &operator[](size_t index);
        std::ostream &operator<<(std::ostream &os);

        void addStudentToList();
        bool searchStudentById(const int id) const;
        void removeStudentById(const int id);
        void showStudentList(void) const;
        friend void showStudentListGPA(); // friend function
    };

} // namespace StudentSystem

#endif // !__STUDENT_H__