#include <iostream>
#include "Linked_List.h"
using namespace std;



Linked_List::Linked_List(){
    head = nullptr;
};

bool Linked_List::Insert(int key, float f){
    ListItem *newNode = new ListItem;

    newNode->key = key;
    newNode->theData= f;
    newNode->next=nullptr;

    if (head == nullptr) { // If the list is empty, set the new item as head
        head = newNode;
        return true;
    }
    // Traverse to the end of the list and insert there
    ListItem* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode; // Add the new item at the end
    return true;
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

void Linked_List::PrintList() {
    ListItem *current = head;

    // Print the header
    cout << "Items in the List\n";
    cout << "-----------------------------------------------------------\n";
    cout << "Key\t\tData\n";
    cout << "-----------------------------------------------------------\n";

    // Print each item in the list
    while (current != nullptr) {
        cout << current->key << "\t\t" << current->theData << endl;
        current = current->next;
    }

    cout << "-----------------------------------------------------------\n";  // Print a footer
}


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


bool Linked_List::Delete(int key) {
    // Check if the list is empty
    if (head == nullptr) {
        return false;
    }

    // Edge case: If the head needs to be deleted
    if (head->key == key) {
        ListItem* dummy = head; // Store the head for deletion
        head = head->next;      // Move head to the next node
        delete dummy;           // Delete the old head
        return true;
    }

    // Traverse the linked list to find the key
    ListItem* current = head; // Start from the head
    while (current->next != nullptr) {
        if (current->next->key == key) { // Check the next node
            ListItem* dummy = current->next; // Store the node to delete
            current->next = current->next->next; // Bypass the node
            delete dummy; // Delete the node
            return true;
        }
        current = current->next; // Move to the next node
    }

    return false; // Key not found
}


bool Linked_List::isEmpty(){
    ListItem *current = head;
    if (current == nullptr){
        return true;
    }else{
        return false;
    }
}

bool Linked_List::isFull(){
    ListItem *current = new (nothrow) ListItem;

    if (current == nullptr){ // nothrow returns a nullptr rather than throwing an error
        return true;
    }
    delete current;
    return false;
}


bool Linked_List::Search(int key, float *retVal){
    ListItem *current = head;

    while (current != nullptr)
    {
       if (current->key == key){
            *retVal = current->theData;
            return true;
       }
       current = current->next;
    }
    return false; 
};


// int main(){

//     Linked_List *thelist;

//     thelist = new Linked_List;

//     thelist->Insert(1, 2.7f);

//     thelist->PrintList();

//     // Test the list length function
//      cout << "\nList now contains " << thelist->ListLength() << " items.\n\n";
// }