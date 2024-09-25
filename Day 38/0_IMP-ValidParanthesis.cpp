#include<iostream>
#include<stack>
using namespace std;

bool idValid(string s){
    stack<char> st;
    int n=s.length();

    for(int i =0 ;i<n ;i++){
        char ch = s[i];
        if(ch =='{' || ch=='(' || ch=='['){
            st.push(ch);
        }
        else{
            if(!st.empty()){
                char top = st.top();
                if((s[i]=='}' && top=='{') || (s[i]==')' && top=='(') || (s[i]==']' && top=='[') ){
                    st.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
    }
    if(st.empty()) return true;
    else return false;
}

int main () 
{
    string s = "({[]})";
    cout<<"Valid Paranthesis : " <<boolalpha<<idValid(s)<<endl;

    string str = "({[({}[][)]})";
    cout<<"Valid Paranthesis : " <<boolalpha<<idValid(str)<<endl;
    return 0;
}