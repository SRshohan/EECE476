#include <iostream>
#include "LinkedStack.h"


using namespace std;

LinkedStack::LinkedStack(int capacity): top(nullptr), maxCap(capacity), current(0) {};

LinkedStack::~LinkedStack(){
    while (!isEmpty())
    {
        pop();
    }
    
};


void LinkedStack::push(int value){
    if (isFull()){
        cout << "Stack is full, new node cant be added! " <<endl;
        return;
    };

    node* newNode = new node;
    newNode->value = value;
    newNode->next = top;
    top = newNode;
    current++;
    return;
};



bool LinkedStack::isEmpty(){
    return top == nullptr;
};


bool LinkedStack::isFull(){
    return current >= maxCap;
};

int LinkedStack::pop(){
 if (isEmpty()){
    cout << "Stack is empty! " <<endl;
    return -1;
 }
  int val = top->value; // Current getting the top value
  node* temp = top;
  top = top->next;
  delete temp;
  current--;
  return val;

};


int LinkedStack::peek(){
    if (isEmpty()){
        cout << "No PEEK value. " << endl;
        return -1;
    };

    return top->value;
};

// int main(){
//     LinkedStack stack = LinkedStack(5);
//     cout<< stack.isEmpty() << endl;

//     stack.push(5);
//     stack.push(10);
//     stack.push(30);

//     cout << "Peek value: " << stack.peek() << endl;

//     stack.pop();

//     cout << "Peek value: " << stack.peek() << endl;



// };

