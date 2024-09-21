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

// Approches 1 : replace data . 
// Node* sortList(Node *head){
//     // Write your code here.
//     int i =0;
//     int j =0;
//     int k =0;
//     Node* temp = head;
//     while(temp!=NULL){
//         if(temp->data == 0)
//             i++;
//         else if(temp->data == 1)
//             j++;
//         else if(temp->data == 2)
//             k++;
//         temp = temp->next;
//     }
//     temp = head;

//     while(temp!=NULL){
//         if(i>0){
//             temp->data = 0;
//             i--;
//         } else if (j > 0) {
//             temp->data = 1;
//             j--;
//         } else if (k > 0) {
//             temp->data = 2;
//             k--;
//         }
//         temp = temp->next;
//     }
//     return head;
// }//Time : O(n) , space : O(1)

//Approch 2 : Make 3LL , merge them. (Data replacement not allowed)
void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}


Node* sortList(Node *head)
{
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    
    Node* curr = head;
    
    // create separate list 0s, 1s and 2s
    while(curr != NULL) {
        
        int value = curr -> data;
        
        if(value == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if(value == 1) {
            insertAtTail(oneTail, curr);
        }
        else if(value == 2) {
            insertAtTail(twoTail, curr);
        }       
        curr = curr -> next;
    }
    
    //merge 3 sublist
    
    // 1s list not empty
    if(oneHead -> next != NULL) {
        zeroTail -> next = oneHead -> next;
    }
    else {
        //1s list -> empty
        zeroTail -> next = twoHead -> next;
    }
    
    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;
    
	//setup head 
    head = zeroHead -> next;
    
    //delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}

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
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);

    printList(head);

    Node* newHead = sortList(head);

    printList(newHead);


    return 0;
}