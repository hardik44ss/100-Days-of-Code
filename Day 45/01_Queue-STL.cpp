#include<iostream>
#include<queue>
using namespace std;

int main() {
    cout << (-1)%1<< endl;
    queue<int> q;

    // Insert elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Display the front and back element
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // Remove an element from the queue
    q.pop();

    // Display the front element after pop
    cout << "Front element after pop: " << q.front() << endl;

    // Check if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    // Display the size of the queue
    cout << "Size of the queue: " << q.size() << endl;
    return 0;
}