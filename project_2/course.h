#ifndef STDUENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;

namespace Students{
    class Student{
        private:
            int student_num;
            vector<string> courses;
        public:
            // Constructor
            Student(int student_num, vector<string> courses);

            int getStudent_num();
            void setName(int student_num);

            virtual void printcourses();
            void addCourses(string name);
            void deleteCourses(string name);

    };
};


#endif