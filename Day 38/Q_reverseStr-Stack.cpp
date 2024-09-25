#include<iostream>
#include<stack>
using namespace std;

//Stack is used in REVERSAL 

int main () 
{
    string s="Hardik";
    stack<char> st;
    for(unsigned int  i=0;i<s.size();i++)
    {
        st.push(s[i]);
    }
    string ans="";

    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    } 
    cout<<ans<<endl;
    return 0;
}
//Time : O(n)
//Space : O(n)