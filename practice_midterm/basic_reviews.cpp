#include <iostream>

using namespace std;


// Defination of Struct

// struct Point
// {
//     /* data */
//     int x;
//     int y;
// };


// Definition of class

// class Point
// {
//     private:
//         int x;
//         int y;

//     public:
//         void setValues(int setx, int sety){
//             x = setx;
//             y = sety;
//         }
//         void printPoint(){
//         cout << "X: " << x << " Y : " << y << endl;
//         }
// };


//Operator (::), member function (.)
// class DayOfYear{
//     public:
//         void output();
//         int x;
//         int y;
// };

// void DayOfYear::output()
// {
//     cout << x << " " << y << endl;
// }


// Constructor
class BankAccount{
    private:
        int balance;
        int interestrate;
    public:
        BankAccount(int dollar, int cents, double rate) : balance(dollar+1+cents), interestrate(rate * dollar) {}; // This is parameterized where balance and interest can be inside the banckaccount
        BankAccount() : balance(0), interestrate(0.0) {}
        void printinfo(){
            cout << balance << " and " << interestrate<<endl;
        }
};




int main(){

    BankAccount account1(14, 50, 0.1), account2;
    account1.printinfo();
    account2.printinfo();

};