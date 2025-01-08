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

    // Create circular linked list by adding a node
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
    // Insert Node
      void insert(int d){
        node *temp = new node(d);
        if(end == NULL){
            end = temp;
            end->next = temp;     //circular link
        }else{
            temp->next = end->next;
            end->next = temp;
        }
    }

     // Insert a node at a specific position
    void insertAtPosition(int position, int d) {
        if (end == NULL || position == 1) {
            insert(d); // If position is 1 or list is empty, use insert at beginning
            return;
        }

        node* temp = end->next; // Start from the head
        int count = 1;

        while (count < position - 1 && temp != end) {
            temp = temp->next;
            count++;
        }

        if (count != position - 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        node* nodeToInsert = new node(d);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;

        if (temp == end) {
            end = nodeToInsert; // Update tail if inserted at the end
        }
    }

    // display circular linked list
    void display(){
        if(end == NULL){
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
    cout<<"Original list: ";
    o1.createNode(10);
    o1.createNode(20); 
    o1.createNode(30);
    o1.createNode(40);
    o1.display();

    cout<<"Insert node: ";
    o1.insert(45);
    o1.display();
    
    cout<<"Insert node at position 3: ";
    o1.insertAtPosition(3 , 68);
    o1.display();
    return 0;
}