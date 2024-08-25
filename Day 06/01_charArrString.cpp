#include<iostream>
#include<vector>
using namespace std;
/*
String : array of chars
At the end : null character 
    - use as terminator (end of array ka pata chalta h)
*/
int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }

    return count;
}

void reverse(char name[], int n) {
    cout<<"Original  : "<<name<<endl;
    int s=0;
    int e = n-1;

    while(s<e) {
        swap(name[s++], name[e--]);
    }
    cout<<"Reverse : "<<name<<endl;
}
bool checkPalindrome(string s)
{
    // Write your code here.
    int st=0;
    int e= s.length()-1;
    while(st<e){
        if(s[st++]!=s[e--]){
            return false;
        }
    }
    return true;
}
char toLower(char a){
    if(a>='a' && a<='z'){
        return a;
    }else{
        return a - 'A' + 'a'; // H - A = 7 + a = h
    }
}

int main () 
{
    char a[20] = "absdfsf";
    a[2]='\0'; //print till index 2
    cout<<a<<endl;
    char name[20];
    cout<<"Enter name : ";
    cin>>name;
    cout<<"YOur name is : "<<name<<endl;
    //Print till ' 'space or null chracter

//Length of the string
    cout<<"Length of a : "<<getLength(name)<<endl;

    char rev[20]="Hardra";
    reverse(rev,6);
    cout<<"Palindromie or not : "<<checkPalindrome(rev)<<endl;

    cout<<"Lower Case : "<<toLower('k')<<endl;
    cout<<"Lower Case : "<<toLower('H')<<endl; 
    return 0;
}