#include<iostream>
#include<map>
using namespace std;

class Node {
public:
        int data;
        Node* next;
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};


void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

// bool isCircularList(Node* head) {
//     //empty list
//     if(head == NULL) {
//         return true;
//     }
//     Node* temp = head -> next;
//     while(temp != NULL && temp != head ) {
//         temp = temp -> next;
//     }
//     if(temp == head ) {
//         return true;
//     }
//     return false;
// }


bool detectLoop(Node* head) {

    if(head == NULL) //Empty list
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {
        cout<<temp->data<<" ";
        //cycle is present
        if(visited[temp] == true) {
            cout << "\nLoop Present on element " << temp->data << endl;
            return true;
        }
        visited[temp] = true;
        temp = temp -> next;
    }
    return false;
}

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

void removeLoop(Node* head) {

    Node* intersection = floydDetectLoop(head);
    Node* slow = head;
    Node* prev = NULL;

    while(slow != intersection) {
        prev = intersection;
        slow = slow -> next;
        intersection = intersection -> next;
    }

    prev -> next = NULL;
    cout << "Loop is removed" << endl;
}



int main() {
    Node* head = new Node(4);
    head -> next = new Node(5);
    head -> next -> next = new Node(6);
    head -> next -> next -> next = new Node(7);
    head -> next -> next -> next -> next = head -> next;

    cout <<"Loop is : "<< boolalpha<< detectLoop(head) << endl;

    if(floydDetectLoop(head) != NULL) {
        cout << "Loop is present" << endl;
    }
    else {
        cout << "Loop is not present" << endl;
    }

    cout << "Starting node of loop is " << getStartingNode(head) -> data << endl;
    

    return 0;
}