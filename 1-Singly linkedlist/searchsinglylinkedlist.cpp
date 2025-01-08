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

// check whether key is present in linkedlist
bool searchkey(node *head, int key){
    // iterate over all nodes
    while(head!= NULL){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

//function to search key in linkedlist by recursive approach
bool searchlinkedlist(node *head, int target){
    if(head== NULL){           // base case
        return false;
    }
    if(head->data==target){
        return true;
    }
    searchlinkedlist(head->next, target);
}

int main(){
    node *head=new node(10);
    head->next= new node(20);
    head->next->next = new node(30);
     head->next->next->next = new node(50);
    head->next->next->next->next = new node(10);
    // key to search in linkedlist
    cout<<"Search node in iterartive approach: ";
    int key;
    key=14;
    if(searchkey(head, key))
    cout<<"Yes";
    else
    cout<<"No";
    cout<<endl;
    // Recursive function calls
    cout<<"Search node in recursive approach: ";
    int target=20;
    if(searchkey(head, target))
    cout<<"Yes";
    else
    cout<<"No";
    return 0;
}