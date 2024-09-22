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

//Merging left and right halves
Node* merge(Node* left, Node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    Node* result = new Node(0);
    Node* temp = result;
    
    // if (left->data <= right->data) {
    //     result = left;
    //     result->next = merge(left->next, right);
    // }
    // else {
    //     result = right;
    //     result->next = merge(left, right->next);
    // } Time Complexity: O(n) Space Complexity: O(n)
    while(left!=NULL && right!=NULL){
        if(left->data <= right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    } 
    while(left!=NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while(right!=NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }
    result = result->next;

    return result;
}
//Merge Sort
Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Find the middle of the linked list
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the linked list into two halves
    Node* left = head;
    Node* right = slow->next;
    slow->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the two sorted linked lists
    Node* result = merge(left , right);
    return result;
}//Time Complexity: O(nlogn) Space Complexity: O(n)

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
    Node* head = new Node(6);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(1);

    // Print the linked list
    printList(head);
    Node* newHead = mergeSort(head);
    printList(newHead);

    return 0;
}

/* Q. Why is Merge Sort preferred over QuickSort for Linked Lists?
Ans: In case of arrays, access time is O(1) and hence pivot selection is easy. In linked list, we can not access elements in O(1) time. QuickSort requires a lot of access which is not possible in linked list. MergeSort accesses data sequentially and the need of random access is low.*/