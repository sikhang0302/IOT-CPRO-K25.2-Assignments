#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <string>
#include <vector>

namespace StudentSystem
{
    class Student
    {
    private:
        static int newId;
        int id;
        std::string name;
        float gpa;

        
        public:
        Student();
        Student(std::string name, float gpa);
        ~Student();
        
        int getId(void) const;
        std::string getName(void) const;
        float getGpa(void) const;
        
        void setNewId(int newCalculatedId);
        void setName(const std::string &name);
        void setGpa(float gpa);

        bool operator==(const int studentId);
        bool operator==(const int studentId) const;

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
        const Student &operator[](size_t index) const;

        void addStudentToList(const std::string &name, const float gpa);
        bool searchStudentById(const int id) const;
        bool removeStudentById(const int id);
        void showStudentList(void) const;

        friend std::ostream &operator<<(std::ostream &os, const StudentList &studentList);
        friend void showStudentListTotalGPA(const StudentList &studentList);
    };

} // namespace StudentSystem

#endif // !__STUDENT_H__