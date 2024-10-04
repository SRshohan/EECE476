#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string &name, int age) : name(name), age(age) {}
    virtual ~Person() {}

    std::string getName() const { return name; }
    int getAge() const { return age; }

    virtual void printname() const {
        std::cout << "This is " << name << std::endl;
    }

    // Pure virtual function for adding courses
    virtual void addCourse(const std::string &course) = 0;
};

#endif

