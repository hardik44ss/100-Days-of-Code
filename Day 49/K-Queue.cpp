#include<iostream>
#include<queue>
using namespace std;

class KQueue{
    public : 
        int n ; 
        int k ;
        int * arr;
        int * next;
        int * front;
        int * rear;
        int freeSpot;

    KQueue(int n , int k){
        this->n = n;
        this->k = k;
        arr  = new int[n];
        next = new int[n];
        for(int i =0 ; i<n ;i++){ next[i] = i+1;}
        next[n-1] = -1;

        front = new int[k]; 
        rear  = new int[k]; 
        for(int i = 0 ; i<k ; i++){
            front[i] =-1;
            rear[i] = -1;
        }
        freeSpot = 0;
    }

    void enQueue(int data , int qn){
        
        //Check for overflow
        if(freeSpot==-1){
            cout<<"No empty space availble\n";
            return;
        }

        //Find first index 
        int index = freeSpot;

        //Update freeSpot 
        freeSpot = next[index];

        //Check whether input is first element
        if(front[qn-1]==-1){
            front[qn-1] = index; //rear element is updated in next step
        }
        else{
            //Link new element with previous 
            next[rear[qn-1]] = index;
        }

        //Update rear element
        rear[qn-1] = index;
        
        //Push element into array 
        arr[index] = data;
    }

    int pop(int qn){

        //Check for underflow
        if(front[qn-1]==-1){
            cout<<"Queue Underflow \n";
            return -1;
        }

        //find index to pop
        int index = front[qn-1];

        //Update front index of queue
        front[qn-1] = next[index];

        //Manage the freespot
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    
};

int main () 
{
    KQueue q(10,3);
    q.enQueue(1,1);
    q.enQueue(2,1);
    q.enQueue(4,2);
    q.enQueue(5,2);
    q.enQueue(7,3);
    q.enQueue(8,3);

    cout<<q.pop(1)<<"\n";
    cout<<q.pop(1)<<"\n";
    cout<<q.pop(2)<<"\n";
    cout<<q.pop(2)<<"\n";
    cout<<q.pop(2)<<"\n";
    cout<<q.pop(2)<<"\n";
    

    return 0;
}