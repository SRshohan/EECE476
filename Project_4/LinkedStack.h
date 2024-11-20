#ifndef LINKED_STACK_H
#define LINKED_STACK_H


struct node
{
    int value;
    node* next;

};

class LinkedStack{
    private:
        node* top;
        int maxCap;
        int current;
    public:
        LinkedStack(int capacity);
        ~LinkedStack();
        void push(int val);
        int pop();
        bool isEmpty();
        bool isFull();
        int peek();
};

#endif
