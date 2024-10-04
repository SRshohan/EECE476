#ifndef STDUENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "person.h"
using namespace std;

namespace Students{
    class Student{
        private:
            int student_num;
            vector<string> courses;
        public:
            // Constructor
            Student(int student_num,  vector<string> courses);

            int getStudent_num();
            void setStudent_num(int student_num);

            void printcourses();
            void addCourses(string name);
            void deleteCourses();
            friend bool operator==(Student& s1, Student& s2);
            void printname() const override;

    };
};


#endif