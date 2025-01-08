#include <iostream>
using namespace std;
 
class node{
    public:
    int data;
    node *next;
    node(int d){
     this->data=d;
     this->next=NULL;
    }
};

// Traversal in linkedlist by iterative approach
void traverseLinkedlist(node *head){
    while(head!=NULL){
    cout<<head->data<<" ";
    head = head->next; 
    }
    cout<<endl;
}

// Traversal in linkedlist by recursive approach
void traverseList(node *head){
    if(head == NULL){      // base case
        cout<<endl;
        return;
    }
    cout<<head->data<< " ";
    traverseList(head->next);
}

node *insertatstart(node *head, int value){
    node *newNode = new node(value);
    newNode->next = head;
    head = newNode;
    return head;
}

int main(){
    node *head = new node(12);
    head->next = new node(15);
    head->next->next = new node(19);
    head->next->next->next = new node(21);
    // original linkedlist
    cout<<"Traversing in linkedlist iteratively: ";
    traverseLinkedlist(head);
    cout<<"Traversing in likedlist recursively: ";
    traverseList(head);

    // insert new node at front of linkedlist
    cout<<"Afater inserting node at front the linkedlist will be: ";
    int value = 6;
    head = insertatstart(head, value);

    // print updated list
    traverseList(head);
    return 0;
}