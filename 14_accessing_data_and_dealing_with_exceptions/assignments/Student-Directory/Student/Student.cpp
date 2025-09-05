#include "Student.hpp"
#include <iostream>
#include <stdexcept>

namespace StudentSystem
{
    Student::Student(int id, std::string name, int age, float gpa)
        : id(id), name(name), age(age), gpa(gpa) {}

    Student::Student() {}

    int Student::getId(void) const { return id; }
    std::string Student::getName(void) const { return name; }
    int Student::getAge(void) const { return age; }
    float Student::getGpa(void) const { return gpa; }

    void Student::setId(int id) { this->id = id; }
    void Student::setName(std::string name) { this->name = name; }
    void Student::setAge(int age) { this->age = age; }
    void Student::setGpa(float gpa) { this->gpa = gpa; }

    void Student::addStudent(int id, std::string name, int age, float gpa)
    {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gpa = gpa;

        return;
    }

    void Student::showInfo(void) const
    {
        std::cout << "Student ID: " << id << std::endl;
        std::cout << "Student Name: " << name << std::endl;
        std::cout << "Student Age: " << age << std::endl;
        std::cout << "Student GPA: " << gpa << std::endl;

        return;
    }

    std::vector<Student> StudentDirectory::getStudentList() const { return studentList; }

    void StudentDirectory::setStudentList(const std::vector<Student> &studentList)
    {
        this->studentList = studentList;
    }

    void StudentDirectory::addStudentToList(const std::string &idStr,
                                            const std::string &nameStr,
                                            const std::string &ageStr,
                                            const std::string &gpaStr)
    {
        int id;
        int age;
        float gpa;
        std::string name = nameStr;
        bool exceptionFound = false;
        size_t pos;

        try
        {
            id = std::stoi(idStr, &pos);

            if (pos != idStr.size())
            {
                throw std::invalid_argument("");
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: Invalid ID." << std::endl;
            exceptionFound = true;
        }

        try
        {
            age = std::stoi(ageStr, &pos);

            if (pos != ageStr.size())
            {
                throw std::invalid_argument("");
            }

            if (age <= 0)
            {
                throw std::out_of_range("Age must be greater than 0.");
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: Invalid age." << std::endl;
            exceptionFound = true;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            exceptionFound = true;
        }

        try
        {
            gpa = std::stof(gpaStr, &pos);

            if (pos != gpaStr.size())
            {
                throw std::invalid_argument("");
            }

            if (gpa < 0.0f || gpa > 10.0f)
            {
                throw std::out_of_range("GPA is out of valid range (from 0.0 to 10.0).");
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Error: Invalid GPA." << std::endl;
            exceptionFound = true;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            exceptionFound = true;
        }

        if (exceptionFound == true)
        {
            return;
        }

        Student s;
        s.addStudent(id, name, age, gpa);
        studentList.push_back(s);
        std::cout << "Successfully added a student!" << std::endl;
    }

    void StudentDirectory::searchStudentById(const int id) const
    {
        for (const auto &s : studentList)
        {
            if (s.getId() == id)
            {
                std::cout << "Found a student with ID: " << id << std::endl;
                s.showInfo();
                return;
            }
        }
        std::cout << "No student with ID: " << id << " found" << std::endl;

        return;
    }

    void StudentDirectory::searchStudentByName(const std::string &name) const
    {
        for (const auto &s : studentList)
        {
            if (s.getName() == name)
            {
                std::cout << "Found a student with name: " << name << std::endl;
                s.showInfo();
                return;
            }
        }
        std::cout << "No student with name: " << name << " found" << std::endl;

        return;
    }

    void StudentDirectory::showStudentList(void) const
    {
        if (studentList.empty())
        {
            std::cout << "Student list is empty." << std::endl;
            return;
        }

        int count = 0;
        for (const auto &s : studentList)
        {
            count++;
            std::cout << "Number " << count << ":" << std::endl;
            s.showInfo();
        }

        return;
    }

    bool isIdExisted(const StudentDirectory &studentList, std::string id)
    {
        if (!(studentList.getStudentList().empty()))
        {
            for (const auto &s : studentList.getStudentList())
            {
                if (std::to_string(s.getId()) == id)
                {
                    return true;
                }
            }
        }
        return false;
    }
} // namespace StudentSystem