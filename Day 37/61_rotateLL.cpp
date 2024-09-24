#include <iostream>
using namespace std;

// Node class to define the structure of each node in the linked list
class Node
{
public:
    int data;   // data field
    Node *next; // pointer to the next node

    // Constructor to initialize a node
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *rotateRight(Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Step 1: Find the length of the list
    int n = 1; // Initialize as 1 since we are counting from head
    Node *temp = head;
    while (temp->next != NULL)
    {
        n++;
        temp = temp->next;
    }

    // Step 2: Link the last node to the first to make it a cycle
    temp->next = head;

    // Step 3: Find the new head of the rotated list
    k = k % n;                  // Handle cases where k >= n
    int stepsToNewHead = n - k; // Position to break the cycle
    Node *newTail = head;
    for (int i = 1; i < stepsToNewHead; i++)
    {
        newTail = newTail->next;
    }

    // Step 4: Break the cycle and set the new head
    Node *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Creating linked list nodes
    Node *head = new Node(1);
    head->next = new Node(2);

    // Print the linked list
    printList(head);

    // Rotate the linked list by 2 positions
    head = rotateRight(head, 1);
    printList(head);
    return 0;
}