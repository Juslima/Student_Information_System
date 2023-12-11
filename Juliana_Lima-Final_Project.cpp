#include <iostream>
#include <iomanip> // for std::fixed and std::setprecision
#include <vector>
#include <algorithm>
#include <string>

class Course {
public:
    std::string name;
    double grade;
};

class Student {
public:
    std::string name;
    int id;
    std::vector<Course> courses;

    double calculateGPA() const {
        if (courses.empty()) {
            return 0.0;
        }

        double totalGrade = 0.0;
        for (const auto& course : courses) {
            totalGrade += course.grade;
        }

        return totalGrade / courses.size();
    }

    double convertTo4Scale(double maxGrade = 100.0) const {
        return (calculateGPA() / maxGrade) * 4.0;
    }
};

class StudentInformationSystem {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void displayStudentDetails() const {
        std::cout << "Student Details:\n";
        for (const auto& student : students) {
            std::cout << "Name: " << student.name << "\n";
            std::cout << "ID: " << student.id << "\n";
            std::cout << "Courses:\n";
            for (const auto& course : student.courses) {
                std::cout << "  - " << course.name << ": " << course.grade << "\n";
            }
            std::cout << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
            std::cout << "GPA: " << student.convertTo4Scale() << "\n\n";
        }
    }

    void displaySpecialFeatures() const {
        // Implementation for special features 
    }
};

int main() {
    StudentInformationSystem sis;

    // Adding initial students
    sis.addStudent({ "Emily Johnson", 123456789, {{"Math", 90.0}, {"History", 85.0}, {"English", 92.5}} });
    sis.addStudent({ "Michael Davis", 987654321, {{"Physics", 88.0}, {"Chemistry", 87.5}, {"Biology", 91.0}} });
    sis.addStudent({ "Sophia Martinez", 246813579, {{"Computer Science", 95.0}, {"Math", 94.5}, {"Physics", 96.0}} });
    sis.addStudent({ "Daniel Thompson", 135792468, {{"History", 80.0}, {"English", 85.5}, {"Biology", 82.0}} });

    int choice;

    do {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Display Student Details\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Add a new student
            Student newStudent;
            std::cout << "Enter student name: ";
            std::cin.ignore(); // Clear the buffer
            std::getline(std::cin, newStudent.name);
            std::cout << "Enter student ID: ";
            std::cin >> newStudent.id;

            // Input courses and grades
            char addMoreCourses;
            do {
                Course course;
                std::cout << "Enter course name: ";
                std::cin.ignore(); // Clear the buffer
                std::getline(std::cin, course.name);
                std::cout << "Enter grade for the course: ";
                std::cin >> course.grade;
                newStudent.courses.push_back(course);

                std::cout << "Do you want to add another course? (y/n): ";
                std::cin >> addMoreCourses;
            } while (addMoreCourses == 'y' || addMoreCourses == 'Y');

            sis.addStudent(newStudent);
            std::cout << "Student added successfully.\n";
            break;
        }
        case 2:
            // Display student details
            sis.displayStudentDetails();
            break;
        case 3:
            // Exit the program
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
