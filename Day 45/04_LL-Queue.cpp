#include<iostream>
using namespace std;

class Node{
        int data;
        Node* next;
    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        friend class LL_Queue;// LinkedListQueue can access private members of Node
};

class LL_Queue{
    private:
        Node* front;
        Node* rear;
    public:
        LL_Queue(){
            front = rear = NULL;
        }
        bool isEmpty(){
            return front == NULL;
        }
        void enqueue(int data){
            Node* newNode = new Node(data);
            if(isEmpty()){
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
                return;
            }
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        int peek(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            return front->data;
        }
        int rearPeak(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
                return -1;
            }
            return rear->data;
        }
        void display(){
            if(isEmpty()){
                cout<<"Queue is empty\n";
                return;
            }
            Node* temp = front;
            while(temp){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"\nPeek : "<<peek()
                <<"\nRear : "<<rearPeak()<<endl<<endl;
        }
};

int main () 
{
    LL_Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.dequeue();
    q.display();

    return 0;
}