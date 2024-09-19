//-------------USING ITERATIVE METHOD----------------//

#include <bits/stdc++.h>
using namespace std;
template <typename T>

class LLNode {
public:
    T data;
    LLNode<T>* next;

    // Constructor to initialize a node with a value
    LLNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to reverse a linked list
LLNode<int>* reverseLinkedList(LLNode<int>* head) {
    if (head == NULL || head->next == NULL)
        return head;

    LLNode<int>* prev = NULL;
    LLNode<int>* curr = head;

    // Iterate through the linked list
    while (curr != NULL) {
        LLNode<int>* nextNode = curr->next; // Store the next node
        curr->next = prev; // Reverse the current node's pointer
        prev = curr; // Move the prev pointer forward
        curr = nextNode; // Move the curr pointer forward
    }
    
    // After the loop, prev will point to the new head of the reversed list
    return prev;
}
//Time Complexity : O(n)
//Space Complexity : O(1)

//Another Method
LLNode<int>* reverse1(LLNode<int>* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    LLNode<int>* newHead = reverse1(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

int main(){
    LLNode<int>* head = new LLNode<int>(1);
    head->next = new LLNode<int>(2);
    head->next->next = new LLNode<int>(3);
    head->next->next->next = new LLNode<int>(4);
    head->next->next->next->next = new LLNode<int>(5);

    LLNode<int>* reversedHead = reverseLinkedList(head);

    LLNode<int>* temp = reversedHead;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout<<"NULL" << endl;

    LLNode<int>* reversedHead1 = reverse1(reversedHead);
    temp = reversedHead1;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout<<"NULL" << endl;

    return 0;
}
