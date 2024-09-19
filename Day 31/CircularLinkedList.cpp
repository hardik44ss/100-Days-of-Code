#include<iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next ;
    
    Node(int data){
        this-> data = data;
        this-> next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};


void insertNode(Node* &tail, int element, int d) {
    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }
}    


void print(Node* tail) {

    Node* temp = tail;

    if(tail == NULL) {//empty list
        cout << "List is Empty "<< endl;
        return ;
    }

    do { //non-empty list
        cout << temp -> data << " -> ";
        temp = temp -> next;
    } while( temp !=tail);

    cout<<tail->data<< endl;
    cout<<"Tail : "<<tail->data<<endl<<endl;
} 

void deleteNode(Node* &tail, int value) {

    cout<<"Deleting Node with value : "<<value<<endl;

    if(tail == NULL) { //empty list
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{//non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        cout<< "curr -> data " << curr -> data << endl;
        cout<< "prev -> data " << prev -> data << endl;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }
}
int main () 
{
    Node* tail = NULL;

    print(tail);
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    insertNode(tail, 5, 9);
    print(tail);

    deleteNode(tail, 3);
    print(tail);
    deleteNode(tail, 5);
    print(tail);
    
    return 0;
}