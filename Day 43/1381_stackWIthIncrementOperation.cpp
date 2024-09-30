#include<iostream>
using namespace std;



class CustomStack {
    int *arr;
    int top;
    int size;
public:
    CustomStack(int maxSize) {
        this->size = maxSize;
         arr = new int[size];
         top = -1;
    }
    
    void push(int x) {
        if(top<size-1){
            top++;
            arr[top] = x;
        }
    }
    
    int pop() {
        if(top>=0){
            int temp = arr[top];
            top--;
            return temp;
            // delete temp;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0 ; i<k && size-i >0;i++){
            arr[i]+=val;
        }
    }
};

int main () 
{
    CustomStack* obj = new CustomStack(3);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    cout<<obj->pop()<<endl;
    obj->increment(2, 100);
    cout<<obj->pop()<<endl;
    cout<<obj->pop()<<endl;
    cout<<obj->pop()<<endl;
    
    
    return 0;
}