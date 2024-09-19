//--------------------Using RECURSION----------------------//

#include<iostream>
using namespace std;
template <typename T>


class Node {
public:
    T data;
    Node<T>* next;

    // Constructor to initialize a node with a value
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

void reverse(Node<int>* &head, Node<int>* &curr, Node<int>* &prev){
    if(curr == NULL){
        head = prev;
        return;
    }
    Node<int> * nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    reverse(head,curr,prev);
}

// Function to reverse a linked list
Node<int>* reverseLinkedList(Node<int>* head){
    Node<int>* prev = NULL;
    Node<int>* curr = head;
    reverse(head,curr,prev);
    return head;
}

int main () 
{
    Node<int>* head = new Node<int>(1);
    head->next = new Node<int>(2);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(4);
    head->next->next->next->next = new Node<int>(5);

    Node<int>* reversedHead = reverseLinkedList(head);

    Node<int>* temp = reversedHead;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout<<"NULL" << endl;


    return 0;
}