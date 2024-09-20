#include<iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next;
        Node* prev;
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" <-> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
    cout<<"Head : "<<head->data<<endl;
}
void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}
void insertAtTail(Node* & head, int data){
    Node* temp = new Node(data);
    if(head==NULL){
        head = temp;
        return;
    }
    Node* temp1 = head;
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    temp1->next=temp;
    temp->prev = temp1;
}

void reverse(Node* &head){
    Node* temp = NULL;
    Node* current = head;
    while(current!=NULL){
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if(temp!=NULL){
        head = temp->prev;
    }
}
void insertAtPosition(Node* &head , int data , int pos){
    Node* temp = new Node(data);
    if(pos==1){
        insertAtHead(head, data);
        return;
    }
    Node* temp1 = head;
    for(int i=1;i<pos-1;i++){
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
    temp->prev = temp1;
    temp->next->prev = temp;
}

int main () 
{
    Node* head = new Node(1);
    print(head); 
    insertAtHead(head, 2);
    print(head);
    insertAtTail(head, 3);
    print(head);
    reverse(head);
    print(head);
    insertAtPosition(head, 4, 2);
    print(head);




    return 0;
}