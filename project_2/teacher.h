#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include <vector>
#include <iostream>

class Teacher : public Person {
private:
    double salary;
    std::vector<std::string> courses; // Use vector for dynamic course list

public:
    Teacher(const std::string &name, int age, double salary) 
        : Person(name, age), salary(salary) {}

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
        std::cout << "This is teacher " << name << std::endl;
    }

    double getSalary() const { return salary; }
};

#endif

