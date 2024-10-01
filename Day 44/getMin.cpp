#include<iostream>
#include<stack>
using namespace std;

class specialStack{
    stack<int> s;
    int mini ;

    public:
        void push(int data){
            if(s.empty()) {
                s.push(data);
                mini = data;
            }else{
                if(data<mini){
                    s.push(2*data-mini);
                    mini =data;
                }else{
                    s.push(data);
                }
            }
        }

        int pop(){
            if(s.empty()) return -1;

            int curr = s.top();
            s.pop();
            if(curr>mini){
                return curr;
            }else{
                int prevMin= mini;
                mini = 2*mini- curr;
                return prevMin;
            }
        }

        int top(){
            if(s.empty()) return -1;

            if(s.top() > mini) return s.top();
            return mini;
        }

        int getMin(){
            if(s.empty()) return -1;
            return mini;
        }
};

int main () 
{
    specialStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Minimum : " << s.getMin() << endl;
    s.push(5);
    cout << "Minimum : " << s.getMin() << endl;
    cout << s.pop() << " is popped" << endl;
    cout << "Minimum : " << s.getMin() << endl;
    cout << s.pop() << " is popped" << endl;
    cout << "Minimum : " << s.getMin() << endl;
    cout << s.pop() << " is popped" << endl;
    cout << "Minimum : " << s.getMin() << endl;

    return 0;
}