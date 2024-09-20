#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void remDuplicate(Node* &head){
    map<int,bool> present;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(present[temp->data]){
            prev->next = temp->next;
            Node* del = temp;
            temp = temp->next;
            delete del;
        }else{
            present[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }

}

int main()
{
    Node *node1 = new Node(4);
    Node *head = node1;
    node1->next = new Node(2);
    node1->next->next = new Node(4);
    node1->next->next->next = new Node(2);
    node1->next->next->next->next = new Node(5);
    node1->next->next->next->next->next = new Node(4);

    print(head);
    remDuplicate(head);
    print(head);

    return 0;
}
// // Solving in O(n^2)
// void remDuplicate(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL && temp->next !=NULL)
//     {
//         Node *curr = temp->next;
//         Node *prev = temp;
//         while (curr !=NULL)
//         {
//             if (temp->data == curr->data)
//             {
//                 prev->next = curr->next;
//                 Node* del = curr;
//                 curr=curr->next;
//                 delete(del);           
//             }else{
//                 prev=curr;
//                 curr=curr->next;
//             }
//         }
//         temp=temp->next;
//     }
// }

/* ----Optimised Solution
1) SortLL + previous ALgo  : O(nlogn)+O(n)

2) Use map (to check presence) : O(n) , Space : O(n)
*/
// void splitList(Node *source, Node **frontRef, Node **backRef)
// {
//     Node *fast;
//     Node *slow;
//     slow = source;
//     fast = source->next;

//     while (fast != NULL)
//     {
//         fast = fast->next;
//         if (fast != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next;
//         }
//     }

//     *frontRef = source;
//     *backRef = slow->next;
//     slow->next = NULL;
// }

// Node *sortedMerge(Node *a, Node *b)
// {
//     Node *result = NULL;

//     if (a == NULL)
//         return b;
//     else if (b == NULL)
//         return a;

//     if (a->data <= b->data)
//     {
//         result = a;
//         result->next = sortedMerge(a->next, b);
//     }
//     else
//     {
//         result = b;
//         result->next = sortedMerge(a, b->next);
//     }
//     return result;
// }

// void mergeSort(Node **headRef)
// {
//     Node *head = *headRef;
//     Node *a;
//     Node *b;

//     if ((head == NULL) || (head->next == NULL))
//     {
//         return;
//     }

//     splitList(head, &a, &b);

//     mergeSort(&a);
//     mergeSort(&b);

//     *headRef = sortedMerge(a, b);
// }

// void remDuplicate(Node *&head)
// {
//     if (!head)
//         return;

//     mergeSort(&head);

//     Node* temp = head;
//     while(temp->next !=NULL){
//         if(temp->data == temp->next->data){
//             Node* del = temp->next;
//             temp->next = temp->next->next;
//             delete del;
//         }else{
//             temp = temp->next;
//         }
//     }
   
// }
