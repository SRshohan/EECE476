#include "person.h"
#include "student.h"
#include "teacher.h"
#include "course.h"
#include <iostream>

int main() {
    // Initialize courses
    Course courses[5] = {
        Course("CS101", "Intro to Computer Science", "Basics of programming"),
        Course("CS102", "Data Structures", "Understanding data organization"),
        Course("CS103", "Algorithms", "Fundamentals of algorithms"),
        Course("CS104", "Operating Systems", "Working with OS concepts"),
        Course("CS105", "Database Systems", "Basics of database management")
    };

    // Initialize persons
    Person *persons[3] = {
        new Student("Alice", 20, 1),
        new Student("Bob", 22, 2),
        new Teacher("Charlie", 35, 50000)
    };

    // Initialize students and teachers
    Student students[3] = {
        Student("Eve", 20, 1),
        Student("Frank", 21, 2),
        Student("Grace", 22, 3)
    };

    Teacher teachers[3] = {
        Teacher("Dr. Smith", 45, 75000),
        Teacher("Prof. Johnson", 50, 80000),
        Teacher("Ms. Davis", 38, 70000)
    };

    // Add courses for students
    students[0].addCourse("CS101");
    students[0].addCourse("CS102");

    // Add courses for teachers
    teachers[0].addCourse("CS101");
    teachers[1].addCourse("CS103");
    teachers[2].addCourse("CS104");

    // Demonstrate operator overload
    if (students[0] == students[1]) {
        std::cout << "Students have the same courses." << std::endl;
    } else {
        std::cout << "Students have different courses." << std::endl;
    }

    // Demonstrate runtime polymorphism
    for (int i = 0; i < 3; ++i) {
        persons[i]->printname();
    }

    // Print information about students and teachers
    for (int i = 0; i < 3; ++i) {
        students[i].printCourses();
        teachers[i].printCourses();
    }

    // Clean up allocated memory for persons
    for (int i = 0; i < 3; ++i) {
        delete persons[i];
    }

    return 0;
};
