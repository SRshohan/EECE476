#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

class Course {
private:
    std::string course_number;
    std::string course_name;
    std::string course_description;

public:
    Course(const std::string &course_number, const std::string &course_name, const std::string &course_description) 
        : course_number(course_number), course_name(course_name), course_description(course_description) {}

    std::string getCourseNumber() const { return course_number; }
    std::string getCourseName() const { return course_name; }
    std::string getCourseDescription() const { return course_description; }
};

#endif
