#include <iostream>
#include "inheritance.h"
using namespace std;


class HourlyEmployee:public Employee{
    public:
        int wage;
        double hourly;
        HourlyEmployee(int wage, double hourly, string name, string ssn);
        void print() override { // Override the base class print
        Employee::print(); // Call the base class print
        cout << "Wage: " << wage << ", Hourly: " << hourly << endl; // Adjusted output format
    }
};


Employee::Employee(string name, string ssn): name(name), ssn(ssn) {};

HourlyEmployee::HourlyEmployee(int wage, double hourly, string name, string ssn) : Employee(name, ssn), wage(wage), hourly(hourly){};


void Employee::setName(string setname){
    name = setname;
}

void Employee::setSsn(string setssn){
    ssn = setssn;
}

string Employee::getName(){
    return name;
}


string Employee::getSsn(){
    return ssn;
};


void Employee::print(){
    cout << "Name: " << name << "SSN: " << ssn;
}


int main(){
    Employee ep1("Sohanur", "2562536");

    HourlyEmployee hr1(12, 13.0, "Soahnur", "123456");

    hr1.print();

    ep1.setName("Sohanur");
    ep1.setSsn("1234");

    ep1.print();

    return 0;
};

