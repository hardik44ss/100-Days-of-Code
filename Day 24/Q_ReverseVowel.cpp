#include<iostream>
using namespace std;

string reverseVowels(string s)
{
    int st = 0;
    int ed = s.length()-1;

    while(st<ed){
        while(st<ed && s[st]!='a' && s[st]!='e' && s[st]!='i' && s[st]!='o' && s[st]!='u'){
            st++;
        }
        while(st<ed && s[ed]!='a' && s[ed]!='e' && s[ed]!='i' && s[ed]!='o' && s[ed]!='u'){
            ed--;
        }
        swap(s[st],s[ed]);
        st++;
        ed--;

    }
    return s;
}
int main () 
{
    string s;
    cin >> s;
    cout << reverseVowels(s) << endl;
    return 0;
}