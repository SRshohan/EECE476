#include "person.h"

Person::Person(const std::string &name, int age) : name(name), age(age) {}

Person::~Person() {}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::printname() const {
    std::cout << "This is " << name << "." << std::endl;
}


