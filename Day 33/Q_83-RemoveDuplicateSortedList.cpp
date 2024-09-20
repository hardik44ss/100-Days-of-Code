#include<iostream>
#include<vector>
using namespace std;

class Node{
    public: 
        int data;
        Node* next;
        Node(int data){
            this-> data = data;
            this-> next = NULL;
        }
};

void print(Node* &head ){
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
}

Node* remDuplicate(Node* head){
    Node* temp = head;
    while(temp->next !=NULL){
        if(temp->data == temp->next->data){
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }else{
            temp = temp->next;
        }
    }
    return head;
} // O(n)

int main () 
{
    Node* node1 = new Node(1);
    Node* head = node1;
    node1->next = new Node(2);
    node1->next->next = new Node(3);
    node1->next->next->next = new Node(3);
    node1->next->next->next->next = new Node(5);

    // int k =3;
    print(head);
    head = remDuplicate(head);
    print(head);




    return 0;
}