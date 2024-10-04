#include <iostream>
#include "student.h"
#include <vector>
#include "person.h"

using namespace std;
using namespace Students;
using namespace Persona;


// Constructor
Student::Student(int student_num, vector<string> courses): student_num(student_num), courses(courses) {};

//setter and getter
int Student::getStudent_num(){
    return student_num;
}

void Student::setStudent_num(int student_num){
    student_num = student_num;
}

void Student::printcourses(){
    for ( string course: courses){
        cout << "Course name: " << course << endl;
    }
}
void Student::addCourses(string course_name){
    courses.push_back(course_name);
};

void Student::deleteCourses(){
    courses.clear();
};


bool Student::operator==(Student& s1, Student& s2){
    if ( s1.courses.size() != s2.courses.size()){
        return false;
    }else{
        for (int i = 0; i < s1.courses.size(); i++){
            if (s1.courses[i] != s2.courses[i]){
                return false;
            }
        }
        return true;
    }
};

void Student::Person::void printname(){
    cout << 
}


