#include <iostream>
using namespace std;


struct ListItem
{
     int      key;          
     float    theData;
      ListItem *next;
};


class LinkedList{
    private:
        ListItem *head = nullptr;
    public:
        LinkedList(){
            head = nullptr;
        };

        void insert(int key, float f){
            ListItem *newNode = new ListItem;

            newNode->key = key;
            newNode->theData= f;
            newNode->next=nullptr;

            newNode->next = head;
            head = newNode;
        };

        int Listlength(){
            ListItem *newNode = head;
            int count = 0;
            while(newNode != nullptr){
                count++;
                newNode = newNode->next;
            }
            return count;
        };

        void PrintList(){
            ListItem *current = head;
            while (current != nullptr)
            {
                cout << "Key: "<< current->key << ", Data: "<< current->theData<<endl;
                current = current->next;
            };
        };

};

int main(){

    LinkedList *thelist;

    thelist = new LinkedList;

    thelist->insert(1, 2.7f);

    thelist->PrintList();

    // Test the list length function
     cout << "\nList now contains " << thelist->Listlength() << " items.\n\n";
}