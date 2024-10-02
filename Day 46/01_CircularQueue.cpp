#include<iostream>
using namespace std;

class CircularQueue{
    int *arr;
    int cFront;
    int cRear;
    int size;

public:
    CircularQueue(int size){
        this->size = size;
        arr = new int[size];
        cFront = cRear = -1;
    }
    void enQueue(int data);
    int deQueue();
    void display();
};
void CircularQueue:: enQueue(int data){
    if((cFront == 0 && cRear == size-1) || (cRear == (cFront-1)%(size-1))){
        cout<<"Queue is full"<<endl;
        return;
    }
    
    if(cFront == -1) //Initialising Queue
        cFront = cRear = 0;
    else if(cRear == size-1 && cFront != 0) 
        cRear = 0;
    else 
        cRear++;

    arr[cRear] = data;
}
int CircularQueue:: deQueue(){
    if(cFront == -1){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    int val = arr[cFront];
    arr[cFront] = -1;
 
    if(cFront == cRear) //Only one element in Queue
        cFront = cRear = -1;
    else if(cFront == size-1) //If front is at last index
        cFront = 0;
    else
        cFront++;
    return val;
}
void CircularQueue:: display(){
    if(cFront == -1){
        cout<<"Queue is empty"<<endl;
        return;
    }
    if(cRear >= cFront){
        for(int i=cFront; i<=cRear; i++)
            cout<<arr[i]<<" ";
    }
    else{ //It mean middle elements are Popped

        for(int i=cFront; i<size; i++)
            cout<<arr[i]<<" ";
        for(int i=0; i<=cRear; i++)
            cout<<arr[i]<<" ";
    }
    cout<<"\nFront: "<<arr[cFront]<<endl;
    cout<<"Rear: "<<arr[cRear]<<endl;
    cout<<endl;
}

int main(){
    CircularQueue q(5);
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.display();
    q.enQueue(60);
    cout<<"Dequeue: "<<q.deQueue()<<endl;
    q.display();
    cout<<"Dequeue: "<<q.deQueue()<<endl;
    q.display();
    cout<<"Dequeue: "<<q.deQueue()<<endl;
    cout<<"Dequeue: "<<q.deQueue()<<endl;
    q.display();
    cout<<"Dequeue: "<<q.deQueue()<<endl;
    q.display();  

   
    return 0;
}