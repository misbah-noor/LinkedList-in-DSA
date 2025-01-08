#include <iostream>
using namespace std;

class node{
   public:
   int data;
   node *next;
   // Constructor to initialize data with value
   node(int d){
    this->data =d;
    this->next = NULL;
   }
   //Default Constructor
   node(){
    this->data=-1;
    this->next=NULL;
   }
};

class Linkedlist{
    public:
    node *start;     //points to first node in the list
    node *ptr;       // points to last node
    Linkedlist(){
        this->start=NULL;
        this->ptr=NULL;
    }
    //create node at the end of list 
    void createNode(int x){
        if(ptr == NULL)
        ptr = start = new node(x);
        else
        ptr->next = new node(x);
        ptr = ptr->next;
    }
    // insert new node at start of list
    void insert(int d){
        node *temp= new node(d);
        temp->next = start;
        start =temp;
    }

    // insert at position
    void insertAtPosition(int position, int data){
        node *temp = start;
        int cnt =1;
        while(cnt< position-1){
            temp = temp-> next;
            cnt++;
        }
        node *nodeToinsert = new node (data);
        nodeToinsert->next = temp->next;
        temp->next = nodeToinsert;
    }

    // insert between
    void insertBetween(int newData,int prevData){
     node *current = start;
     while(current && current->data != NULL){
        current = current->next;
        if( current == NULL){
            cout<<"Node with data"<<prevData<<"not found"<<endl;
            return;
        }
     }
     node *newNode =  new node(newData);
     newNode->next= current->next;
     current->next = newNode;
    }

    //delete node
    void deleteNode(int value){
     if(start->data == value){
        node *temp = start;
        start = start->next;
        delete temp;
        return;
     }
     node *current = start;
     while(current->next != NULL && current->data != value){
        current = current->next;
     } 
     if(current->next == NULL){
        cout<<"Node with value"<<value<<"not found. "<<endl;
        return;
     }
     node *temp = current->next;
     current->next= current->next->next;
     delete temp;
    }

    //print linkedlist
    void display(){
        node *t= start;
        while(t != NULL){
            cout<<t->data<<endl;
            t = t->next;
        }
    }
};

int main(){
    Linkedlist o1;
    o1.createNode(10);
    o1.createNode(34);
    o1.createNode(121);
    o1.display();

    o1.insert(45);
    o1.display();

    o1.insertAtPosition(2,5088888);
	o1.display();
	
	o1.insertBetween(50, 34);
    cout << "List after inserting 50 between 34 and 121:" << endl;
    o1.display();
    
    o1.deleteNode(50); 
    o1.deleteNode(10);  
    cout << "List after deleting node with value 10:" << endl;

    return 0;
}