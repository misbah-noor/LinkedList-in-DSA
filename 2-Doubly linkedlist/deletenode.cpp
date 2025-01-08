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

    //  Delete node by value
    void deleteNode(int d){
         node *temp = start;

         // find the node with specified value
         while(temp !=NULL && temp->data !=d){
            temp = temp->next;
         }

         if(temp == NULL){
            cout<<"Node with value "<<d<<" not found."<<endl;
            return;
         }


         // if the node to delete is the first node
         if(temp == start){
         start = temp->next;
         if(start != NULL){
            start->prev == NULL;
         }
         else{
            end = NULL;           // list is now empty
         }
         }
         else if(temp == end){        // if node to delete the last node
          end = temp->prev;
          end->next = NULL;
         }
         else{          //if node is in middle
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
         }
         delete temp;    //free memory
    }

    // Display linkedlist
    void display(){
        node *temp = start;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main(){
    Linkedlist o1;
    cout<<"Original Doubly Linkedlist: ";
    o1.createNode(10);
    o1.createNode(20);
    o1.createNode(30);
    o1.display();
    cout<<endl;
    cout<<"After Deleting node 20: ";
    o1.deleteNode(20);
    o1.display();
    return 0;
}