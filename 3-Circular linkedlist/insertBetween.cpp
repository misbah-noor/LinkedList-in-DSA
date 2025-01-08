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

     // Insert a node between two values
    void insertBetween(int newData, int prevData) {
        if (end == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        node* current = end->next;

        do {
            if (current->data == prevData) {
                node* newNode = new node(newData);
                newNode->next = current->next;
                current->next = newNode;

                if (current == end) {
                    end = newNode; // Update tail if inserted at the end
                }
                return;
            }
            current = current->next;
        } while (current != end->next);

        cout << "Node with data " << prevData << " not found." << endl;
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
    cout<<"Original list: ";
    o1.createNode(10);
    o1.createNode(20); 
    o1.createNode(30);
    o1.createNode(40);
    o1.display();
   
    cout<<"Insert node between 30 and 40: ";
    o1.insertBetween(96 , 30);
    o1.display();
    return 0;
}