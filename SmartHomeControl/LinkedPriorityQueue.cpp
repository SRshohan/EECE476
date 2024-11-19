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


void LinkedPriorityQueue::pop(){

}

void LinkedPriorityQueue::push(int priority, string alert){
    if (isFull()){
        cout << "Queue is full! " << endl;
        return;
    }


}

bool LinkedPriorityQueue::isEmpty(){
    return head == nullptr;
}

bool LinkedPriorityQueue::isFull(){
    return false;
}


