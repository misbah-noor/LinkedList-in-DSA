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

    void insertNode(int value){
        node *newNode = new node(value);
        if(start == NULL){
            start = end = newNode;
        }
        else{
            newNode->next =start;
            start->prev = newNode;
            start = newNode;
        }
    }

    //********* Insert node at specific position *********//

    void insertAtposition(int position, int value){
       if(position == 1){        // insert at the beginning
       insertNode(value);
       return;
       }
       node *temp = start;
       int count = 1;
       // traverse the position
       while(temp != NULL && count < position-1){
        temp = temp->next;
        count++;
       }
       if(temp == NULL){
        cout<<"Invalid position!"<<endl;
        return;
       }

       node *newNode= new node(value);
       newNode->next = temp->next;
       if(temp->next != NULL){
        temp->next->prev = newNode;
       }
       temp->next = newNode;
       newNode->prev = temp;

       // update and inserted at last position
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

    cout<<"After inserting node: ";
    o1.insertNode(60);
    o1.display();
    cout<<endl;

    cout<<"Insert node at position 3: ";
    o1.insertAtposition(3, 89);
    o1.display();
    return 0;
}