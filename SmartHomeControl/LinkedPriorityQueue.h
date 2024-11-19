#ifndef LINKED_PRIORITY_QUEUE_H
#define LINKED_PRIORITY_QUEUE_H

#include <iostream>
#include <string>
using namespace std;


struct QueueNode{
    int priority;
    string alert;
    QueueNode* next;
};

class LinkedPriorityQueue{
    private:
        QueueNode *head;
    public:
        LinkedPriorityQueue();
        ~LinkedPriorityQueue();
        void pop();
        void push(int priority, string alert);
        bool isFull();
        bool isEmpty(); 
};




#endif