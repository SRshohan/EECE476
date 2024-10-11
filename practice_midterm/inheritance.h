#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee{
    private:
        string name;
        string ssn;
    public:
        Employee(string name, string ssn);
        void setName(string setname);
        void setSsn(string setssn);
        string getName();
        string getSsn();
        virtual void print();
};

#endif