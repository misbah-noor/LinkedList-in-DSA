#include <iostream>
using namespace std;

class node{
   public:
   int data;
   node *next;
   node *prev;
   node(int d){
    this->data = d;
    this->next =NULL;
    this->prev =NULL;
   }
};

class linkedlist{
     public:
     node *start;
     node *end;
    linkedlist(){
    start = end = NULL;
    }

    void createNode(int d){
        node *newNode = new node(d);
        if(start == NULL){
            start = end = newNode;
        }
        else{
            end->next = newNode;
            newNode->prev = end;
            end = newNode;
        }
    }

    // insert node between two specific values
    void insertBetween(int newData, int prevData){
     node *temp =start;

     //find node with specified data
     while(temp != NULL && temp->data !=prevData){
        temp = temp->next;
     }
     if(temp == NULL){
        cout<<"Node with value"<<prevData<<"not found."<<endl;
        return;
     }

     node *newNode = new node(newData);
     newNode->next = temp->next;
     if(temp->next != NULL){
        temp->next->prev = newNode;
     }
     temp->next = newNode;
     newNode->prev = temp;

     //update end if inserted at the last position
     if(newNode->next == NULL){
        end = newNode;
     }
    }
 

    void display(){
        node *temp = start;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp= temp->next;
        }
    }
};

int main(){
    linkedlist o1;
    cout<<"Original List: ";
    o1.createNode(10);
    o1.createNode(20);
    o1.createNode(30);
    o1.createNode(40);
    o1.display();
    cout<<endl;

    cout<<"Insert node between 30 and 40: ";
    o1.insertBetween(14, 30);
    o1.display();
    return 0;
}