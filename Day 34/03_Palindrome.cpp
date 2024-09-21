#include <iostream>
#include <vector>
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

// bool checkPalindrome(Node* head){
//     //By storing value in array
//     vector<int> arr;
//      while(head!=NULL){
//             arr.push_back(head->data);
//             head=head->next;
//         }
//         int i =0 ;
//         int j = arr.size()-1;
//         while(i<j){
//             if(arr[i]!=arr[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
// }// Space : O(n) , Time : O(n)
Node *getMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool checkPalindrome(Node *head)
{
    // check middle , reverse (mid,end)
    if (head == NULL || head->next == NULL)
        return true;
    Node *mid = getMiddle(head);
    Node *midNext = mid->next;

    // Reverse the second half
    Node *prev = NULL;
    Node *curr = midNext;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    midNext = prev;
    // Compare the first and second half
    Node *temp1 = head;
    Node *temp2 = midNext;
    while (temp1 != midNext && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
} //pace : O(1) , Time : O(n)

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
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Print the linked list
    printList(head);
    cout << "Is Palindrome : " << boolalpha << checkPalindrome(head) << endl;

    return 0;
}