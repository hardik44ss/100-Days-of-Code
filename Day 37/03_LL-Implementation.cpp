#include<iostream>
using namespace std;

/* Linked List Implementation of stack

Q.: Why Linked List? 
A.: When Size of stack not known in advance.
    No limitation on number of nodes to be pushed.

Q.: Why should we prefer beginning of LL as top of stack?
A.: For push - node can be inserted at beginning in O(1) time.
    For pop - node can be deleted from beginning in O(1) time.
         (In case of end, it will take O(n) time to reach end node)

Stack overFlow : When no space left in memory to allocate new node.
               : In that case malloc() will return NULL.
Stack underFlow : When top is NULL and pop() is called.
*/
struct Node{
    int data;
    Node * next;
};

class LinkListStack {
    private : 
        Node * top;
    public : 
        LinkListStack(){
            top = NULL;
        }
        void push(int data){
            Node * newNode = new Node();
            cout<<"Pushing "<<data<<endl;
            newNode->data = data;
            newNode->next = top;
            top = newNode;
        }
        int pop(){
            if(top == NULL){
                cout<<"Stack UnderFlow  ";
                return -1;
            }
            int ans = top->data;
            Node * temp = top;
            top = top->next;
            // cout<<"Popping "<<ans<<endl;
            delete temp;
            return ans;
        }
        int peek(){
            if(top == NULL){
                cout<<"Stack is Empty"<<endl;
                return -1;
            }
            return top->data;
        }
        bool isEmpty(){
            return top == NULL;
        }
};


int main () 
{
    LinkListStack st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout<<"Top : " << st.peek()<<endl;
    cout<<"Popping : " <<st.pop()<<endl;
    cout<<"Top : " << st.peek()<<endl;
    cout<<"Popping : " <<st.pop()<<endl;

    cout<<"Is Empty : " <<st.isEmpty()<<endl;
    cout<<"Poppint : " <<st.pop()<<endl;
    cout<<"Poppint : " <<st.pop()<<endl;

    cout<<"Is Empty : " << st.isEmpty()<<endl;

    return 0;
}