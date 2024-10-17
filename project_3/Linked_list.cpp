#include <iostream>
#include "Linked_List.h"
using namespace std;



Linked_List::Linked_List(){
    head = nullptr;
};

void Linked_List::Insert(int key, float f){
    ListItem *newNode = new ListItem;

    newNode->key = key;
    newNode->theData= f;
    newNode->next=nullptr;

    newNode->next = head;
    head = newNode;
};

int Linked_List::ListLength(){
    ListItem *newNode = head;
    int count = 0;
    while(newNode != nullptr){
        count++;
        newNode = newNode->next;
    }
    return count;
};

void Linked_List::PrintList(){
    ListItem *current = head;
    while (current != nullptr)
    {
        cout << "Key: "<< current->key << ", Data: "<< current->theData<<endl;
        current = current->next;
    };
};

Linked_List::~Linked_List(){
    ClearList();
};

void Linked_List::ClearList(){
    ListItem *dummy = nullptr;
    ListItem *current = head;

    while (current != nullptr){
        dummy = current;
        current = current->next;
        delete dummy;
    }
    head = nullptr;
};


bool Linked_List::Delete(int key){
    ListItem *current = head;
    ListItem *dummy = nullptr;


    if (head == nullptr){
        return false;
    };


    // Edge case: If head needs to delete
    if (current->key == key){
        dummy = current;
        current = current->next;
        delete dummy;
        return true;
    };

    //Traverse the linkedlist
    while (current != nullptr){
        if (current->next->key = key){
            dummy = current->next;
            current->next = current->next->next;
            delete dummy;
            return true;
        };
        current = current->next;   
    };
    head = current;
    return false;
};


int main(){

    Linked_List *thelist;

    thelist = new Linked_List;

    thelist->Insert(1, 2.7f);

    thelist->PrintList();

    // Test the list length function
     cout << "\nList now contains " << thelist->ListLength() << " items.\n\n";
}