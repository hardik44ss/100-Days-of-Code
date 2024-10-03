#include<iostream>
#include<stack>
#include<queue>

using namespace std;

queue<int> modifyQueue(queue<int> q, int k) {
  
        stack<int> s;
        
        for(int i = 0; i<k; i++) {
            int val = q.front();
            q.pop();
            s.push(val);
        }
        
        while(!s.empty()) {
            int val = s.top();
            s.pop();
            q.push(val);
        }
        
        int t = q.size()-k;
        
        while(t--) {
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        return q;
}
void display(queue<int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main () 
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(75);
    q.push(54);
    q.push(22);
    q.push(44);

    display(q);
    q = modifyQueue(q, 3);
    display(q);


    return 0;
}