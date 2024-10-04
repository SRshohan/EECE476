#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include <vector>
#include <iostream>

class Student : public Person {
private:
    int student_num;
    std::vector<std::string> courses; // Use vector for dynamic course list

public:
    Student(const std::string &name, int age, int student_num) 
        : Person(name, age), student_num(student_num) {}

    void addCourse(const std::string &course) override {
        courses.push_back(course);
    }

    void printCourses() const {
        std::cout << "Courses: ";
        for (const auto &course : courses) {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }

    void printname() const override {
        std::cout << "This is student " << name << std::endl;
    }

    // Other methods...
    int getStudentNum() const { return student_num; }

    // Friend function for operator overload
    friend bool operator==(const Student &s1, const Student &s2) {
        return s1.courses == s2.courses;
    }
};

#endif

