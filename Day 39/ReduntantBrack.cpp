#include<iostream>
#include<stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(unsigned int  i=0; i<s.length(); i++) {
        char ch =s[i];
        
        if(ch == '(' || ch == '+' ||ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else
        {
            //ch ya toh ')' hai or lowercase letter
            
            if(ch == ')') {
                bool isRedundant = true;
                
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' ||top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();
                }
                
                if(isRedundant == true)
                    return true;
                st.pop();
            }
            
        } 
    }
    return false;
}

int main () 
{
    string s = "((a+b))";
    if(findRedundantBrackets(s)) {
        cout<<s<<" , Reduntant: "<<"Yes"<<endl;
    }
    else
    {
        cout<<s<<" , Reduntant : " <<"No"<<endl;
    }

    string str = "(a+(b-c))";
    if(findRedundantBrackets(str)) {
        cout<<str<<" , Reduntant: "<<"Yes"<<endl;
    }
    else
    {
        cout<<str<<" , Reduntant : " <<"No"<<endl;
    }

    return 0;
}