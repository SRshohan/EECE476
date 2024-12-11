// Implement a BankAccount Class
// Create a BankAccount class that holds information about a user's bank balance. The class should include:

// A private member balance that stores the balance of the account.
// A constructor that initializes the balance.
// A public method deposit that increases the balance by a given amount.
// A public method withdraw that decreases the balance by a given amount (if there are sufficient funds).
// A friend function printBalance that can access and display the balance.

#include <iostream>
using namespace std;

class Bankaccount {
    private:
        double balance;
    Bankaccount();

    public:
        Bankaccount(double initialbalance = 0.0) : balance(initialbalance){};

        void deposit(double amount){
            if (amount > 0 ){
                balance += amount;
            }else{
                cout << "Invalid error" << endl;
            }
        }
        void withdraw(double amount){
            if (balance < amount){
                cout << "Invalid amount to withdraw" << endl;
            }else{
                balance -= amount;
            };
        }
        friend void printbalance(const Bankaccount& account); // Account is to hold the value and using & to ensure we can hold the Bankacount temporarily
};

void printbalance(const Bankaccount& account){
    cout << "The amount is: " << account.balance << endl;
}

int main(){

    Bankaccount myaccount(100.0);

    myaccount.deposit(40.0);
    myaccount.withdraw(90);
    printbalance(myaccount);

    return 0;
};