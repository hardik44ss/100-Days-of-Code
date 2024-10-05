//Input : 11 12 13 14 15 16 17 18 
//Output : 11 15 12 16 13 17 14 18
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/* 1.Approch
        Fetch 1st half in new queue
        push alternatively into first queue
*/
//https://drive.google.com/file/d/1vYBC7PjRFfFBdfON1bc8-JrO8Ve07JCA/view page41
void shiftElement(queue<int> &q , int n){
    // queue<int> newQ;
    // for(int i=0 ;i<n/2;i++){
    //     newQ.push(q.front());
    //     q.pop();
    // }
    // while(!newQ.empty()){
    //     q.push(newQ.front());
    //     newQ.pop();
    //     q.push(q.front());
    //     q.pop();
    // }

    //`2.Approch : Implement using stack 
    stack<int> s;
    // Fetch 1st half in stack
    for(int i=0 ;i<n/2;i++){
        s.push(q.front());
        q.pop();
    }
    // Push 1st half(stack) in queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    // Push 2nd half in queue
    for(int i=0 ;i<n/2;i++){
        q.push(q.front());
        q.pop();
    }
    // Push 1st half in queue
    for(int i=0 ;i<n/2;i++){
        s.push(q.front());
        q.pop();
    }
    // Push 1st half(stack) in queue
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main () 
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);

    shiftElement(q , q.size());
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }



    return 0;
}