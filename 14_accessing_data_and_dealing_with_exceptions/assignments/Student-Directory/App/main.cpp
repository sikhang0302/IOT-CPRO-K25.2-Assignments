#include "../Student/Student.hpp"
#include <iostream>
#include <stdexcept>

int main(void)
{
    StudentSystem::StudentDirectory studentList;

    int choice = 0;
    do
    {
        std::cout << "======================= MENU =======================" << std::endl;
        std::cout << "1. Add new student information" << std::endl;
        std::cout << "2. Show list of student" << std::endl;
        std::cout << "3. Search student by ID" << std::endl;
        std::cout << "4. Search student by name" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << ">> Select:  ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
        {
            std::string id;
            std::string name;
            std::string age;
            std::string gpa;

            try
            {
                std::cout << "Enter student ID: ";
                std::getline(std::cin, id);
                if (!(StudentSystem::isIdExisted(studentList, id)))
                {
                    std::cout << "Enter student name: ";
                    std::getline(std::cin, name);

                    std::cout << "Enter student age: ";
                    std::getline(std::cin, age);

                    std::cout << "Enter student GPA: ";
                    std::getline(std::cin, gpa);

                    studentList.addStudentToList(id, name, age, gpa);
                }
                else
                {
                    throw std::exception("ID is already existed!");
                }
            }
            catch (const std::exception &e)
            {
                std::cout << "Error: " << e.what() << std::endl;
            }

            break;
        }

        case 2:
        {
            std::cout << "Current List: " << std::endl;
            studentList.showStudentList();
            break;
        }

        case 3:
        {
            std::string idStr;
            int id;
            std::cout << "Enter an ID to search: ";
            std::getline(std::cin, idStr);

            try
            {
                id = std::stoi(idStr);
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << "Error: Invalid ID." << std::endl;
                break;
            }

            studentList.searchStudentById(id);

            break;
        }

        case 4:
        {
            std::string name;
            std::cout << "Enter a name to search: ";
            std::getline(std::cin, name);

            studentList.searchStudentByName(name);

            break;
        }

        case 0:
        {
            std::cout << "Exitting the program..." << std::endl;
            break;
        }

        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}