#include <iostream>
using namespace std;

class node{
   public:
   int data;
   node *next;
   node *prev;
   node(int d){
    this->data=d;
    this->next=NULL;
    this->prev=NULL;
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

    // display linkedlist
    void displayForward(){
        node *temp = start;
        cout<<"Forward traversal in Linkedlist: ";
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void displayBackward(){
        node *temp = end;
        cout<<"Backward traversal in linkedlist: ";
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }
};

int main(){
    Linkedlist o1;
    o1.createNode(10);
    o1.createNode(20);
    o1.createNode(30);
    o1.createNode(40);
    o1.createNode(50);
    
    o1.displayForward();
    o1.displayBackward();
    return 0;
}