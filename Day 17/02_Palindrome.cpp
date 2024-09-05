#include<iostream>
using namespace std;

bool checkPalindrome(string str,int i , int j ){
    if(i>j){
        return 1;
    }
    if(str[i]!=str[j]){
        return 0 ; 
    }
    return checkPalindrome(str, ++i , --j);
}


bool isPalindrome(string str){
    int i=0,j=str.length()-1;
    return checkPalindrome(str,i,j);

}

int main () 
{
    string name = "hardik";
    cout <<"Is hardik palindrome : " << boolalpha<< isPalindrome(name) << endl;
    string name2 = "harrah";
    cout <<"Is harrah palindrome : " <<boolalpha<< isPalindrome(name2) << endl;
    return 0;
}