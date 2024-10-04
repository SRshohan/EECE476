#include <iostream>
#include "person.h"

using namespace std;
using namespace Persona;

Person::Person(string name, int age): name(name), age(age) {};

//Destructor
Person::~Person(){};

// Setters and getters
void Person::setName(string name){
    this->name = name;
};
string Person::getName(){
    return name;
};

void Person::setAge(int age){
    this->age = age;
};

int Person::getAge(){
    return age;
};

void Person::printname(){
    cout << "This is " << name << "." << age << " is the age" << endl;
};


int main(){
    Person myname("Sohanur", 28);
    myname.printname();

    // You can also modify and access the name and age
    myname.setName("John");
    myname.setAge(30);

    myname.printname();

};



