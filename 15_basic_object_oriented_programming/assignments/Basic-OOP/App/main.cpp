#include "../Student/Student.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

int main(void)
{
    StudentSystem::StudentList studentList;

    std::string choiceStr;
    int choice = -1;
    size_t pos;

    do
    {
        try
        {
            std::cout << "======================= MENU =======================\n";
            std::cout << "1. Add new student\n";
            std::cout << "2. Change name of a student by ID\n";
            std::cout << "3. Change GPA of a student by ID\n";
            std::cout << "4. Remove a student by ID\n";
            std::cout << "5. Show list of student\n";
            std::cout << "6. Show total GPA of all student\n";
            std::cout << "0. Exit\n";
            std::cout << ">> Select: ";

            std::getline(std::cin, choiceStr);
            choice = std::stoi(choiceStr, &pos);

            if (pos != choiceStr.size())
            {
                throw std::invalid_argument("");
            }

            switch (choice)
            {
            case 1:
            {
                std::string name;
                std::string gpaStr;
                float gpa;

                std::cout << "Enter student name: ";
                std::getline(std::cin, name);

                std::cout << "Enter student GPA (from 0.0 to 10.0): ";
                std::getline(std::cin, gpaStr);
                
                try
                {
                    gpa = std::stof(gpaStr, &pos);

                    if (pos != gpaStr.size())
                    {
                        throw std::invalid_argument("");
                    }

                    if (gpa < 0.0f && gpa > 10.0f)
                    {
                        throw std::out_of_range("");
                    }

                    studentList.addStudentToList(name, gpa);
                }
                catch (const std::invalid_argument &e)
                {
                    std::cout << "GPA must be a float number!\n";
                }
                catch (const std::out_of_range &e)
                {
                    std::cout << "GPA is out of valid range (from 0.0 to 10.0)!\n";
                }
            }
            break;

            case 2:
            {
                std::string idStr;
                int id;

                std::cout << "Enter ID of student: ";
                std::getline(std::cin, idStr);

                try
                {
                    id = std::stoi(idStr, &pos);

                    if (pos != idStr.size())
                    {
                        throw std::invalid_argument("");
                    }

                    if (!(studentList.searchStudentById(id)))
                    {
                        std::cout << "No student with ID " << id << " found\n";
                    }
                    else
                    {
                        std::string newName;
                        std::cout << "Enter new name for student with ID " << id << ": ";
                        std::getline(std::cin, newName);

                        studentList[id - 1].setName(newName);
                        std::cout << "Successfully changed student name!\n";
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    std::cout << "ID must be an integer number!\n";
                }
            }
            break;

            case 3:
            {
                std::string idStr;
                int id;

                std::cout << "Enter ID of student: ";
                std::getline(std::cin, idStr);

                try
                {
                    id = std::stoi(idStr, &pos);

                    if (pos != idStr.size())
                    {
                        throw std::invalid_argument("");
                    }

                    if (!(studentList.searchStudentById(id)))
                    {
                        std::cout << "No student with ID " << id << " found\n";
                    }
                    else
                    {
                        std::string newGpaStr;
                        float newGpa;
                        std::cout << "Enter new GPA for student with ID " << id << ": ";
                        std::getline(std::cin, newGpaStr);

                        try
                        {
                            newGpa = std::stof(newGpaStr, &pos);

                            if (pos != newGpaStr.size())
                            {
                                throw std::invalid_argument("");
                            }

                            if (newGpa < 0.0f && newGpa > 10.0f)
                            {
                                throw std::out_of_range("");
                            }

                            studentList[id - 1].setGpa(newGpa);
                            std::cout << "Successfully changed student GPA!\n";
                        }
                        catch (const std::invalid_argument &e)
                        {
                            std::cout << "GPA must be a float number!\n";
                        }
                        catch (const std::out_of_range &e)
                        {
                            std::cout << "GPA is out of valid range (from 0.0 to 10.0)!\n";
                        }
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    std::cout << "ID must be an integer number!\n";
                }
            }
            break;

            case 4:
            {
                std::string idStr;
                int id;

                std::cout << "Enter ID of student: ";
                std::getline(std::cin, idStr);

                try
                {
                    id = std::stoi(idStr, &pos);

                    if (pos != idStr.size())
                    {
                        throw std::invalid_argument("");
                    }

                    if (!(studentList.removeStudentById(id)))
                    {
                        std::cout << "No student with ID " << id << " found\n";
                    }
                    else
                    {
                        std::cout << "Successfully removed student with ID " << id << "\n";
                    }
                }
                catch (const std::invalid_argument &e)
                {
                    std::cout << "ID must be an integer number!\n";
                }
            }
            break;

            case 5:
            {
                studentList.showStudentList();
            }
            break;

            case 6:
            {
                showStudentListTotalGPA(studentList);
            }
            break;

            case 0:
            {
                std::cout << "Exiting the program...\n";
            }
            break;
            default:
            {
                std::cout << "Invalid choice! Please try again\n";
                break;
            }
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Choice must be an integer number! Please try again.\n";
            choice = -1;
        }

        std::cout << "\n";
    } while (choice != 0);

    return 0;
}