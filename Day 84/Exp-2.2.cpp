// Important Bullet Points for the Experiment (Union and Intersection of Two Linked Lists using Hashing)
// - Data Structure: Linked List with nodes containing data and pointers to the next node.
// - Hashing: 
//   - Union: Combine all distinct elements from both lists.
//   - Intersection: Find common elements between both lists.
// - Approach: 
//   - Use `unordered_set` for efficient O(1) average time complexity for insertions and lookups.
//   - Traverse both lists and insert elements into sets.
//   - For union, insert all elements from both lists into a set.
//   - For intersection, insert elements that appear in both sets into the result list.
// - Efficiency: The time complexity of the union and intersection operations is O(n + m), where `n` and `m` are the lengths of the two lists.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* getUnion(Node* head1, Node* head2) {
    unordered_set<int> set;
    Node* result = nullptr;

    while (head1) {
        set.insert(head1->data);
        head1 = head1->next;
    }

    while (head2) {
        set.insert(head2->data);
        head2 = head2->next;
    }

    for (int val : set) {
        insert(result, val);
    }

    return result;
}

Node* getIntersection(Node* head1, Node* head2) {
    unordered_set<int> set1, set2;
    Node* result = nullptr;

    while (head1) {
        set1.insert(head1->data);
        head1 = head1->next;
    }

    while (head2) {
        if (set1.find(head2->data) != set1.end()) {
            set2.insert(head2->data);
        }
        head2 = head2->next;
    }

    for (int val : set2) {
        insert(result, val);
    }

    return result;
}

int main() {
    Node* head1 = nullptr;
    Node* head2 = nullptr;

    insert(head1, 10);
    insert(head1, 15);
    insert(head1, 4);
    insert(head1, 20);

    insert(head2, 8);
    insert(head2, 4);
    insert(head2, 2);
    insert(head2, 10);

    cout << "List 1: ";
    printList(head1);

    cout << "List 2: ";
    printList(head2);

    Node* unionList = getUnion(head1, head2);
    cout << "Union: ";
    printList(unionList);

    Node* intersectionList = getIntersection(head1, head2);
    cout << "Intersection: ";
    printList(intersectionList);

    return 0;
}
/*
List 1: 20 4 15 10 
List 2: 10 2 4 8 
Union: 4 15 10 20 2 8 
Intersection: 10 4 
*/