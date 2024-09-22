#include<iostream>
using namespace std;

// Node class to define the structure of each node in the linked list
class Node {
public:
    int data;   // data field
    Node* next; // pointer to the next node

    // Constructor to initialize a node
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};



// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Creating linked list nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Print the linked list
    printList(head);

    return 0;
}