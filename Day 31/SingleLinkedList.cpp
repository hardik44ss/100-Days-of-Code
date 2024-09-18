#include <iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;
        Node(int data){
            this-> data = data;
            this-> next = NULL;
        }
        //Destructor to dynamically free the memory
        ~Node(){
            int value = this-> data;
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory is free for Node with data : "<<value<<endl;
        }
};

void print(Node* &head , Node* &tail){
    if(head == NULL){
        cout<<"List is Empty "<<endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    cout<<" -Head : "<<head->data<<endl;
    cout<<" -Tail : "<<tail->data<<endl<<endl;
}

void insertAtHead(Node* & head , int data){
    
    cout<<"Inserting "<<data<<" at Head"<<endl;
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail (Node* &tail , int data){
    cout<<"Inserting "<<data<<" at Tail"<<endl;
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
    
}

void insertAtPosition(Node* &head, Node* &tail ,int pos, int data){
    
    if(pos==1){//If inserting at 1st position
        insertAtHead(head,data);
        return;
    }
    //Traverse till Previous node of position occurs
    Node* temp = head;
    int cnt=1;

    for( ; cnt<pos-1 ; cnt++){
        temp = temp-> next;
    }
    cout<<"Temp node before "<<pos<<" : "<< temp-> data <<endl;

    //Check if temp at last(tail)
    if(temp->next == NULL){
        insertAtTail(tail,data);
        return ;
    }
    cout<<"Inserting "<<data<<" at "<<pos<<endl;
    Node* newNode = new Node(data);
    newNode-> next = temp-> next;
    temp-> next = newNode;
}   

void deleteNode(Node* &head,Node* &tail , int pos){
    cout<<"Deleting node at "<<pos<<endl;
    
    if(pos==1){//If deleting at head
        Node* temp = head; //To delete data at pos = 1

        head = head-> next;
        temp->next = NULL; //Remember node is still pointing to new Head        
        delete temp; //Destructor is called
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr = curr->next;
            cnt++;
        }
        cout<<"-Curr Data : "<<curr->data<<endl;
        cout<<"-Prev Data : "<<prev->data<<endl;
        
        prev-> next = curr ->next;
        if(curr->next ==NULL){
            tail = prev;
        }
        curr-> next = NULL;
        delete curr;

    }
}


int main() {
    Node* node1 = new Node(4);
    Node* head = node1;
    Node* tail=node1;
    print(head,tail);

    insertAtHead(head, 3);
    print(head,tail);

    insertAtTail(tail,5);
    print(head,tail);
    
    insertAtPosition(head,tail,1,6);
    print(head,tail);

    insertAtPosition(head,tail,3,11);
    print(head,tail);

    insertAtPosition(head,tail,6,13);
    print(head,tail);

    deleteNode(head,tail,1);
    print(head,tail);

    deleteNode(head,tail,3);
    print(head,tail);

    deleteNode(head,tail,4);
    print(head,tail);
    
    return 0;
}