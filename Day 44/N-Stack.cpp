#include<iostream>
#include<stack>
using namespace std;

class NStack{
    int *arr;
    int *top;
    int *next;
    int free;
    int s,n;
    public:
        NStack(int n, int s){
            this->n = n;
            this->s = s;
            arr = new int[s];
            top = new int[n];
            next = new int[s];
            free = 0;
            for(int i=0;i<n;i++) top[i] = -1;
            for(int i=0;i<s-1;i++) next[i] = i+1;
            next[s-1] = -1;
        }

        void push(int data, int sn){
            if(free == -1){
                cout << "Stack Overflow" << endl;
                return;
            }
            int i = free;
            free = next[i];
            next[i] = top[sn];
            top[sn] = i;
            arr[i] = data;
            cout << "Pushed " << data << " to stack " << sn << endl;
        }

        int pop(int sn){
            if(top[sn] == -1){
                cout << "Stack Underflow" << endl;
                return -1;
            }
            int i = top[sn];
            top[sn] = next[i];
            next[i] = free;
            free = i;
            return arr[i];
        }

        int getTop(int sn){
            if(top[sn] == -1){
                cout << "Stack Underflow" << endl;
                return -1;
            }
            return arr[top[sn]];
        }

        bool isEmpty(int sn){
            return top[sn] == -1;
        }

};

int main () 
{
    NStack s(3, 10);

    // Push operations
    s.push(10, 0);
    s.push(20, 0);
    s.push(30, 0);
    s.push(40, 1);
    s.push(50, 1);
    s.push(60, 2);

    // Get top operations
    cout << "Top of stack 0: " << s.getTop(0) << endl;
    cout << "Top of stack 1: " << s.getTop(1) << endl;
    cout << "Top of stack 2: " << s.getTop(2) << endl;

    // Pop operations
    cout << s.pop(0) << " is popped from stack 0" << endl;
    cout << s.pop(1) << " is popped from stack 1" << endl;
    cout << s.pop(2) << " is popped from stack 2" << endl;

    // Get top after pop operations
    cout << "Top of stack 0 after pop: " << s.getTop(0) << endl;
    cout << "Top of stack 1 after pop: " << s.getTop(1) << endl;
    cout << "Top of stack 2 after pop: " << s.getTop(2) << endl;

    // Check if stacks are empty
    cout << "Is stack 0 empty? " << (s.isEmpty(0) ? "Yes" : "No") << endl;
    cout << "Is stack 1 empty? " << (s.isEmpty(1) ? "Yes" : "No") << endl;
    cout << "Is stack 2 empty? " << (s.isEmpty(2) ? "Yes" : "No") << endl;
    return 0;
}