#include<iostream>
using namespace std;

/* Types of Stack Implementation 
    1. Array Implementation
    2. Linked List Implementation
    3. STL Stack Implementation
*/

// Array Implementation of stack 
//Why : When Size of stack is known in advance.
class Stack{
    private : 
        int * arr ; 
        int size; 
        int top;
    public : 
        Stack (int size){
            this->size = size;
            arr = new int[size];
            top=-1;
        }
        void push(int data){
            if(size - top >1){
                top++;
                arr[top]=data;
            }else{
                cout<<"Stack OverFlow "<<endl;
            }
        }
        int pop(){
            if(top>=0){
                int ans = arr[top];
                top--;
                return ans;
            }else{
                cout<<"Stack UnderFlow "<<endl;
            }
        }
        int peek(){
            if(top>=0) 
                return arr[top];
            else{
                cout<<"Stack is Empty "<<endl;
                return -1;
            } 
        }

        int stack_size(){
            return top+1;
        }
        
        bool isEmpty(){
            if (top == -1) return top;
            else  return false;
        }

};

int main () 
{   
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    
    cout << "\nTop Element: " << st.peek() << endl;
    cout << "Size: " << st.stack_size() << endl;
    cout << "Empty or Not: " << st.isEmpty() << endl;

    st.push(60);

    cout<<"Poped Element: "<<st.pop()<<endl;
    cout<<"Poped Element: "<<st.pop()<<endl;

    cout << "\nTop Element: " << st.peek() << endl;
    cout << "Size: " << st.stack_size() << endl;
    cout << "Empty or Not: " << st.isEmpty() << endl;

    cout<<"Poped Element: "<<st.pop()<<endl;
    cout<<"Poped Element: "<<st.pop()<<endl;
    cout<<"Poped Element: "<<st.pop()<<endl;

    cout << "\nTop Element: " << st.peek() << endl;
    cout << "Size: " << st.stack_size() << endl;
    cout << "Empty or Not: " << st.isEmpty() << endl;

    return 0;
}