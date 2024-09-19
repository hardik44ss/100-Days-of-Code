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

/*

*/

Node* reverseKgroup(Node* head, int k){
    Node* check = head;
        for(int i = 0 ; i<k;i++){
            if(check ==NULL){
                return head;
            }
            check = check->next;
        }
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int cnt = 0;

    while(curr!=NULL && cnt<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if(next!=NULL){
        head->next = reverseKgroup(next,k);
    }
    return prev;
    
}
int main () 
{
    Node* node1 = new Node(1);
    Node* head = node1;
    node1->next = new Node(2);
    node1->next->next = new Node(3);
    node1->next->next->next = new Node(4);
    node1->next->next->next->next = new Node(5);

    int k =3;
    print(head);
    Node* newHead = reverseKgroup(head,k);
    print(newHead);


    return 0;
}