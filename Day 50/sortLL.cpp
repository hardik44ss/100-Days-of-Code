#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* findMid(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node *a, Node *b) {
    Node *dummy = new Node(0);
    Node *temp = dummy;
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->next = a;
            a = a->next;
        } else {
            temp->next = b;
            b = b->next;
        }
        temp = temp->next;
    }
    if(a != NULL) {
        temp->next = a;
    } else {
        temp->next = b;
    }
    return dummy->next;
}

Node* sortLL(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node *mid = findMid(head);
    Node *nextMid = mid->next;
    mid->next = NULL;
    Node *left = sortLL(head);
    Node *right = sortLL(nextMid);
    return merge(left, right);

}

int main () 
{
    Node *head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(4);


    return 0;
}