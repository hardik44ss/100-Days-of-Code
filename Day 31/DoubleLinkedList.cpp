#include <iostream>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this-> data = data;
            this-> next = NULL;
            this-> prev = NULL;
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
        cout<<"List is Empty "<<endl<<endl;
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

void insertAtHead(Node* & head , Node* &tail , int data){
    
    cout<<"Inserting "<<data<<" at Head"<<endl;
    //If list is empty
    if(head==NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* & head , Node* &tail , int data){
    
    cout<<"Inserting "<<data<<" at Tail"<<endl;
    //If list is empty
    if(head==NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        tail-> next = temp;
        temp-> prev = tail;
        tail=temp;
    }
}


void insertAtPosition(Node* &head, Node* &tail ,int pos, int data){
    
    if(pos==1){//If inserting at 1st position
        insertAtHead(head,tail,data);
        return;
    }

    //Traverse till Previous node of position occurs
    Node* temp = head;
    int cnt=1;
    for(;cnt<pos-1 ; cnt++){
        temp = temp-> next;
    }
    cout<<"Temp node before "<<pos<<" : "<< temp-> data <<endl;

    if(temp->next == NULL){//Check if temp at last(tail)
        insertAtTail(head,tail,data);
        return ;
    }

    cout<<"Inserting "<<data<<" at "<<pos<<endl;
    Node* newNode = new Node(data);
    temp->next->prev = newNode;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode-> prev = temp;
}   


void deleteNode(Node* &head,Node* &tail , int pos){
    cout<<"Deleting node at "<<pos<<endl;
    
    if(pos==1){//If deleting at head
        Node* temp = head; 
        temp->next->prev=NULL;
        head = temp->next;
        temp->next = NULL;
          
        delete temp; 
    }
    else{
        Node* curr = head;
        Node* prvs = NULL;

        int cnt=1;
        while(cnt<pos){
            prvs=curr;
            curr = curr->next;
            cnt++;
        }
        cout<<"-Curr Data : "<<curr->data<<endl;
        cout<<"-Prev Data : "<<prvs->data<<endl;
        
        prvs-> next = curr ->next;
        if(curr->next ==NULL){
            tail = prvs;
        }
        curr-> next = NULL;
        delete curr;

    }
}


int main() {
    Node* head=NULL;
    Node* tail=NULL;
    print(head ,tail);

    insertAtHead(head,tail,11);
    print(head,tail);
    insertAtHead(head,tail,12);
    print(head,tail);

    insertAtTail(head,tail,10);
    print(head,tail);

    insertAtPosition(head,tail,3,15);
    print(head,tail);

    deleteNode(head,tail,3);
    print(head,tail);

    deleteNode(head,tail,1);
    print(head,tail);

    deleteNode(head,tail,2);
    print(head,tail);

    return 0;
}