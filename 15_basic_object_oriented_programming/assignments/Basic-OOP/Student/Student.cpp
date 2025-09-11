#include "Student.hpp"
#include <iostream>

namespace StudentSystem
{
    int Student::id = 0; // Static member ID must be initalized outside of Student class

    Student::Student() { id++; }
    Student::Student(std::string name, float gpa)
        : name(name), gpa(gpa) { id++; }

    Student::~Student() {}

    void Student::setNewId(int id) { Student::id = id; }

    int Student::getId(void) const { return id; }
    std::string Student::getName(void) const { return name; }
    float Student::getGpa(void) const { return gpa; }

    void Student::setName(const std::string &name) { this->name = name; }
    void Student::setGpa(float gpa) { this->gpa = gpa; }

    bool Student::operator==(const int studentId)
    {
        if (this->id == studentId)
        {
            return true;
        }
        return false;
    }

    void Student::addStudent(const std::string &name, float gpa)
    {
        this->name = name;
        this->gpa = gpa;
    }

    void Student::showInfo(void) const
    {
        std::cout << "Student ID: " << id << "\n";
        std::cout << "Student Name: " << name << "\n";
        std::cout << "Student GPA: " << gpa << "\n";
    }

    // STUDENT LIST
    StudentList::StudentList() {}
    StudentList::StudentList(const std::vector<Student> &studentList)
        : studentList(studentList) {}
    StudentList::~StudentList() {}

    std::vector<Student> StudentList::getStudentList(void) const
    {
        return studentList;
    }

    void StudentList::setStudentList(std::vector<Student> &studentList)
    {
        this->studentList = studentList;
    }

    Student &StudentList::operator[](size_t index)
    {
        return studentList[index];
    }

    std::ostream &StudentList::operator<<(std::ostream &os)
    {
        int count = 0;
        for (auto s : this->getStudentList())
        {
            count++;
            os << "Student " << count << "\n"
               << "- ID: " << s.getId() << "\n"
               << "- Name: " << s.getName() << "\n"
               << "- GPA: " << s.getGpa() << "\n";
        }
        return os;
    }

    bool StudentList::searchStudentById(const int id) const
    {
        if (this->getStudentList().empty())
        {
            std::cout << "List is currently empty!\n";
        }
        else
        {
            int i = 0;
            StudentList a;
            for (i = 0; i < this->getStudentList().size(); i++) {
                if (a[i] == id) {

                }
            }
            for (auto s : this->getStudentList())
            {
                if (s == id)
                {
                    return true;
                }
            }
        }
        return false;
    }

    void StudentList::removeStudentById(const int id)
    {
    }
    void StudentList::showStudentList(void) const
    {
    }
} // namsespace StudentSystem