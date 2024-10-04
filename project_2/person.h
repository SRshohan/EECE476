// person.h

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

namespace Persona {
    class Person{
       private:
            int age;
            string name;
       public:
        Person(string name, int age);
        ~Person();
        string getName();
        void setName(string name);
        int getAge();
        void setAge(int age);
        virtual void printname();
    };
};

#endif 