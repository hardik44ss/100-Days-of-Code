#include <iostream>
#define SIZE 5
using namespace std;

class ArrayQueue {
private:
    int front, rear;
    int arr[SIZE];

public:
    ArrayQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return (rear == SIZE - 1);
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        front++;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout<<"\nFront: "<<arr[front]
            <<"\nRear : "<<arr[rear]
            <<"\nSize : "<<rear-front+1<<endl<<endl; //-1 indexing
    }
};

int main() {
    ArrayQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.enqueue(60);
    q.display();
    return 0;
}