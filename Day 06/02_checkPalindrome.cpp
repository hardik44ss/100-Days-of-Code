#include<iostream>
#include<vector>
using namespace std;

char toLower(char a){
    if(a>='a' && a<='z'){
        return a;
    }else{
        return a - 'A' + 'a'; // H - A = 7 + a = h
    }
}


bool checkPalindrome(string s)
{
    string newStr = "";
     for (char c : s) {
        if (isalnum(c)) { // Check if the character is alphanumeric
            newStr += c;
        }
    }
    // Write your code here.
    int st=0;
    int e= newStr.length()-1;
    while(st<e){
        if(toLower(newStr[st++])!=toLower(newStr[e--])){
            return false;
        }
    }
    return true;
}

int main () 
{
    string s="121H#ard#r$aH121";
    cout << checkPalindrome(s) << endl;

    return 0;
}