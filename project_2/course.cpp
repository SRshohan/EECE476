#include "course.h"

Course::Course(const std::string &course_num, const std::string &course_name, const std::string &course_description)
    : course_num(course_num), course_name(course_name), course_description(course_description) {}

Course::~Course() {}

std::string Course::getCourseNum() const {
    return course_num;
}

std::string Course::getCourseName() const {
    return course_name;
}

std::string Course::getCourseDescription() const {
    return course_description;
}


