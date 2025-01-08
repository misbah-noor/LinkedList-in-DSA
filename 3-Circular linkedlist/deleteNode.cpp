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

class circularlinkedlist{
   public:
   node *end;
   circularlinkedlist(){
    end = NULL;
   }

   void createNode(int x){
    node *newNode = new node(x);

    if(end == NULL){
        end = newNode;
        end->next = end;     //circular link
    }
    else{
        newNode->next = end->next;
        end->next = newNode;
        end = newNode;       // update end
    }
   }

   // Delete a node with a specific value
    void deleteNode(int value) {
        if (end == NULL) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        node* current = end->next;
        node* prev = end;

        do {
            if (current->data == value) {
                if (current == end) {
                    if (end == end->next) { // Only one node
                        delete end;
                        end = NULL;
                        return;
                    } else {
                        prev->next = end->next;
                        end = prev;
                    }
                } else {
                    prev->next = current->next;
                }

                delete current;
                return;
            }

            prev = current;
            current = current->next;
        } while (current != end->next);

        cout << "Node with value " << value << " not found." << endl;
    }

    void display(){
        if(end == NULL){
        cout<<"List is empty."<<endl;
        return;
        }

        node *t = end->next;   //start from head
        do{
            cout<<t->data<<" ";
            t = t->next;
        }while(t != end->next);   //stop when we loop back to the head

        cout<<endl;
    }
};

int main(){
    circularlinkedlist o1;
    cout<<"Original cll: ";
    o1.createNode(5);
    o1.createNode(9);
    o1.createNode(2);
    o1.createNode(7);
    o1.display();

    cout<<"Delete node2: ";
    o1.deleteNode(2);
    o1.display();     
    return 0;
}