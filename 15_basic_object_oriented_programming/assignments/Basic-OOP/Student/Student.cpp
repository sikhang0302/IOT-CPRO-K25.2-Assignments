#include "Student.hpp"
#include <iostream>
#include <stdexcept>

namespace StudentSystem
{
    int Student::newId = 0; // Static member ID must be initalized outside of Student class

    Student::Student() : id(++newId), name(""), gpa(0.0f) {}
    Student::Student(std::string name, float gpa)
        : id(++newId), name(name), gpa(gpa) {}

    Student::~Student() {}

    void Student::setNewId(int newCalculatedId)
    {
        id = newCalculatedId;
        newId--;
    }

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

    bool Student::operator==(const int studentId) const
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

    const Student &StudentList::operator[](size_t index) const
    {
        return studentList[index];
    }

    std::ostream &operator<<(std::ostream &os, const StudentList &studentList)
    {
        int count = 0;
        for (auto s : studentList.getStudentList())
        {
            count++;
            os << "Student " << count << "\n"
               << "- ID: " << s.getId() << "\n"
               << "- Name: " << s.getName() << "\n"
               << "- GPA: " << s.getGpa() << "\n";
        }
        return os;
    }

    void StudentList::addStudentToList(const std::string &name, const float gpa)
    {
        Student tempStudent;
        tempStudent.addStudent(name, gpa);
        bool isPushBack = true;

        // Check for ID
        int i;
        for (i = 0; i < static_cast<int>(studentList.size() - 1); i++)
        {
            if (((*this)[i].getId() + 1) != (*this)[i + 1].getId())
            {
                int id = (*this)[i].getId() + 1;
                tempStudent.setNewId(id);
                studentList.insert(studentList.begin() + (i + 1), tempStudent);
                isPushBack = false;
                break;
            }
        }

        if (isPushBack)
        {
            studentList.push_back(tempStudent);
        }
        std::cout << "Successfully added a Student to the list.\n";
    }

    bool StudentList::searchStudentById(const int id) const
    {
        if (studentList.empty())
        {
            std::cout << "List is currently empty!\n";
        }
        else
        {
            size_t i = 0;
            for (i = 0; i < studentList.size(); i++)
            {
                if ((*this)[i] == id)
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool StudentList::removeStudentById(const int id)
    {
        if (studentList.empty())
        {
            std::cout << "List is currently empty!\n";
        }
        else
        {
            size_t i = 0;
            for (i = 0; i < studentList.size(); i++)
            {
                if ((*this)[i] == id)
                {
                    studentList.erase((studentList.begin()) + i);
                    return true;
                }
            }
        }
        return false;
    }

    void StudentList::showStudentList(void) const
    {
        if (studentList.empty())
        {
            std::cout << "List is currently empty!\n";
        }
        else
        {
            std::cout << "Current list of student: " << "\n"
                      << (*this);
        }
    }

    void showStudentListTotalGPA(const StudentList &studentList)
    {
        if (studentList.getStudentList().empty())
        {
            std::cout << "List is currently empty!\n";
        }
        else
        {
            std::cout << "Current number of student: "
                      << studentList.getStudentList().size()
                      << "\n";

            float totalGpa = 0.0f;
            size_t i;
            for (i = 0; i < studentList.getStudentList().size(); i++)
            {
                totalGpa += studentList[i].getGpa();
            }
            totalGpa /= studentList.getStudentList().size();

            std::cout << "Total GPA of student in the list: " << totalGpa << "\n";
        }
    }
} // namsespace StudentSystem