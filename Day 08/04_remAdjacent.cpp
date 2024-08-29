#include<iostream>
#include<string>
using namespace std;

string removeOccurrences(string s, string part){
    int found = s.find(part);
    int n=s.length();
    while(found<n && found>=0){
        s.erase(found, part.length());
        found=s.find(part);
    }
    return s;
}

int main () 
{
    string str ("There are two needles in this haystack with needles.");
    string str2 ("needle");
    cout<<removeOccurrences(str,str2);

    return 0;
}