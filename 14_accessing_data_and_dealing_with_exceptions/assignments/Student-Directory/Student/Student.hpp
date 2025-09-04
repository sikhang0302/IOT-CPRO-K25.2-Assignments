#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>
#include <vector>

namespace StudentSystem
{
    class Student
    {
    private:
        int id;
        std::string name;
        int age;
        float gpa;

    public:
        Student(int id, std::string name, int age, float gpa);
        Student();

        int getId(void) const;
        std::string getName(void) const;
        int getAge(void) const;
        float getGpa(void) const;

        void setId(int id);
        void setName(std::string name);
        void setAge(int age);
        void setGpa(float gpa);

        void addStudent(int id, std::string name, int age, float gpa);
        void showInfo(void) const;
    };

    class StudentDirectory
    {
    private:
        std::vector<Student> studentList;

    public:
        std::vector<Student> getStudentList() const;

        void setStudentList(const std::vector<Student> &studentList);

        void addStudentToList(const std::string &id, const std::string &name,
                              const std::string &age, const std::string &gpa);
        void searchStudentById(const int id) const;
        void searchStudentByName(const std::string& name) const;
        void showStudentList(void) const;
    };

    bool isIdExisted(const StudentDirectory& studentList, std::string id);
} // namespace StudentSystem

#endif // !__STUDENT_H__