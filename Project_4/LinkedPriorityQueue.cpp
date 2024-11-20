#include <iostream>
#include "LinkedPriorityQueue.h"

using namespace std;

LinkedPriorityQueue::LinkedPriorityQueue(): head(nullptr){

};

LinkedPriorityQueue::~LinkedPriorityQueue(){
    while (!isEmpty()){
        pop();
    };
};


string LinkedPriorityQueue::pop(){
    if (isEmpty()){
        cout << "The Queue is empty, there is nothing to pop!" <<endl;
    }

    QueueNode* temp = head;
    string alert = head->alert;

    head = head->next;
    delete temp;
    return alert;

}

void LinkedPriorityQueue::push(int priority, string alert){

    QueueNode* newNode = new QueueNode;
    newNode->priority = priority;
    newNode->alert = alert;

    if (isEmpty() || newNode->priority < priority){
        newNode->next = head;
        head = newNode;
    } else{
        QueueNode* current = head;
        while (current->next != nullptr && current->next->priority >= priority){
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    };
};

bool LinkedPriorityQueue::isEmpty(){
    return head == nullptr;
};

bool LinkedPriorityQueue::isFull(){
     return false;
};


