#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        this->data=val;
        this->next= NULL;
    }
};

//iterative approach

int findlength(Node *head){
    // initialize counter length to 0
    int length= 0;
    // pointer to current node and assign head to it
    Node *current= head;
    while(current!= NULL){
      length++;
      current = current->next;
    }
    return length;
}


//recursive approach

int countnodes(Node *head){
    if(head == NULL){
        return 0; 
    }

    //count this node plus the rest of list
    return 1 + countnodes(head->next);
}

int main(){
    Node *current= new Node(10);
    current->next = new Node(20);
    current->next->next = new Node(30);
    current->next->next->next = new Node(40);
    // function to call length of nodes
     cout<<"Length of linkedlist is: "<<findlength(current)<<endl;
    Node *head= new Node(5); 
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(4);
    //function call to count the number of nodes
    cout<<"Length of countnodes is: "<< countnodes(head);
    return 0;
}