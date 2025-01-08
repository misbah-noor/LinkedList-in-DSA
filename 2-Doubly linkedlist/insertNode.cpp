#include <iostream>
using namespace std;

class node{
   public:
   int data;
   node *next;
   node *prev;
   node(int d){
   this->data = d;
   this->next = NULL;
   this->prev = NULL;
   }
};

class Linkedlist{
    public:
    node *start;
    node *end;
    Linkedlist(){
        start = end = NULL;
    }

    // create new node and add it to the end of list
    void createNode(int value){
        node *newNode = new node(value);
        if(start == NULL){              // If list is empty
            start = end = newNode;
        }
        else{
            end->next = newNode;
            newNode->prev = end;
            end = newNode;
        }
    }

    // insert node at beginning of list
    void insert(int d){
        node *newNode = new node(d);
        if(start == NULL){
            start = end = newNode;
        }
        else{
            newNode->next = start;
            start->prev = newNode;
            start = newNode;
        }
    }

    // display list
    void display(){
        node *temp = start;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp =temp->next;
        }
    }
};

int main(){
    Linkedlist o1;
    cout<<"Nodes in linkedlist: ";
    o1.createNode(10);
    o1.createNode(20);
    o1.createNode(30);
    o1.display();
    cout<<endl;
    cout<<"After inserting node at start: ";
    o1.insert(12);
    o1.display();
    
    return 0;
}