#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int d){
        data = d;
        next = NULL;
    }
    node(){
        data = -1;
        next = NULL;
    }
};

class CircularLinkedList{
    public:
    node *end;
    CircularLinkedList(){
        end = NULL;
    }

    // create circular linked list by adding a node
    void createNode(int x){
        node *newNode = new node(x);
        if(end == NULL){
            end = newNode;
            end->next = end;   // circular linked list
        }
        else{
            newNode->next = end->next;
            end->next = newNode;
            end = newNode;        // update end
        }
    }

    // display circular linked list
    void display(){
        if( end == NULL){
            cout<<"List is empty."<<endl;
            return;
        }
        node *t = end->next;       // start from head
        do{
            cout<<t->data<<" ";
            t = t->next;
        }while(t != end->next);  //stop when we loop back to head
        cout<<endl;
    }
};


int main(){
    CircularLinkedList o1;
    cout<<"Circular linkedist: ";
    o1.createNode(10);
    o1.createNode(20); 
    o1.createNode(30);
    o1.createNode(40);
    o1.display();
    return 0;
}