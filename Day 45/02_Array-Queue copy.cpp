//Implementation of Queue using Array
#include <iostream>
using namespace std;

class Queue {
        int front, rear, size;
        int* arr;
    public:
        Queue(int s) {
            front = rear = 0;
            size = s;
            arr = new int[s];
        }

        void enQueue(int value);
        int deQueue();
        void displayQueue();
        int getFront(){ return arr[front];}
        int getRear(){ return arr[rear-1];}
        int getSize(){ return size;}
};

void Queue::enQueue(int value) {
    if(rear == size) {
        cout << "\nQueue is full";
    } else {
        arr[rear] = value;
        rear++;
    }
}

int Queue::deQueue() {
    if(front == rear) {
        cout << "\nQueue is empty";
        return -1;
    } else {
        int value = arr[front];
        arr[front] = -1;
        front++;
        return value;
    }
}

void Queue::displayQueue() {
    if(front == rear) {
        cout << "\nQueue is Empty";
    } else {
        cout << "\nQueue : ";
        for(int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout<<"\nFront: "<<getFront()
            <<"\nRear : "<<getRear()
            <<"\nSize : "<<getSize()<<endl;
    }
}

int main(){
    Queue q(4);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.displayQueue();
    cout << "\nDequeued value: " << q.deQueue();
    q.displayQueue();
    return 0;
}
