#include "teacher.h"

Teacher::Teacher(const std::string &name, int age, double salary)
    : Person(name, age), salary(salary) {}

Teacher::~Teacher() {}

double Teacher::getSalary() const {
    return salary;
}

void Teacher::printCourses() const {
    std::cout << "Teacher Courses: ";
    for (const auto &course : courses) {
        std::cout << course << " " << '\n';
    }
}

void Teacher::printname() const {
    std::cout << "This is teacher " << name << "." << std::endl;
};
