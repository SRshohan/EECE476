#include "student.h"

Student::Student(const std::string &name, int age, int student_num)
    : Person(name, age), student_num(student_num) {}

Student::~Student() {}

int Student::getStudentNum() const {
    return student_num;
}

void Student::printCourses() const {
    std::cout << "Courses: ";
    for (const auto &course : courses) {
        std::cout << course << " ";
    }
    std::cout << std::endl;
}

void Student::addCourse(const std::string &course) {
    courses.push_back(course);
}

void Student::deleteCourse(const std::string &course) {
    courses.erase(std::remove(courses.begin(), courses.end(), course), courses.end());
}

bool operator==(const Student &s1, const Student &s2) {
    return s1.courses == s2.courses;
}

void Student::printname() const {
    std::cout << "This is student " << name << "." << std::endl;
}


