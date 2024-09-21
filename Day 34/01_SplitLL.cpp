#include<iostream>
using namespace std;

class Node{
    public :
        int data;
        Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Split the circular linked list
void splitLL(Node* head, Node **head1, Node **head2){
    Node *slow = head;
    Node *fast = head->next;

    // Use slow and fast pointers to find the middle of the list
    while(fast != head && fast->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Head of the first half
    *head1 = head;
    
    // Head of the second half
    *head2 = slow->next;
    
    // Make the first half circular
    slow->next = *head1;
    
    // Make the second half circular
    Node *curr = *head2;
    while(curr->next != head){
        curr = curr->next;
    }
    curr->next = *head2;
}

// Print a circular linked list
void print(Node* head){
    Node* temp = head;
    if (head != NULL) {
        do{
            cout<<temp->data<<"->";
            temp = temp->next;
        }while(temp != head);
    }
    cout<<"NULL"<<endl;
}

int main () 
{
    // Create a linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;

    // Making it circular
    head->next->next->next->next->next = head;

    cout << "Original : ";
    print(head);

    Node *head1 = NULL;
    Node *head2 = NULL;

    // Split the list
    splitLL(head, &head1, &head2);

    cout << "First : ";
    print(head1);
    
    cout << "Second : ";
    print(head2);

    return 0;
}
