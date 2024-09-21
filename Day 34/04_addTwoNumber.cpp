#include<iostream>
using namespace std;


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

Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* dummy = new Node(0); // dummy node to simplify the code
        Node* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->data;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum %= 10;
            current->next = new Node(sum);
            current = current->next;
        }

        return dummy->next;
    }


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
    // Create a linked list
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);
    
    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    cout<<"List1 : ";
    printList(l1);
    cout<<"List2 : ";
    printList(l2);

    Node* result = addTwoNumbers(l1, l2);
    cout<<"Result : ";
    printList(result);

    return 0;
}