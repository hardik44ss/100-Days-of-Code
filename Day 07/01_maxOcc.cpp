#include<iostream>
#include<vector>
using namespace std;

char getMaxOccChar(string s ){
    int arr[26]={0};
    for(int i=0;i<s.size();i++){
        int number = s[i]-'a';
        arr[number]++;
    }
    int max=0;
    char c;
    for(int i=0;i<26;i++){
        if(arr[i]>max){
            max=arr[i];
            c = 'a'+i;
        }
    }
    return c;
}

char maxOccChar(string s){
    int maxCount=0;
    int count=0;
    char maxChar;

    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s[i]==s[j]){
                count++;
            }
        }
        if(count>maxCount){
            maxCount=count;
            maxChar=s[i];
        }
    }
    return maxChar;
}
/*1910 : remove occurence
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)<s.length()){
            s= s.erase(s.find(part),part.length());
        }
        return s;
    }
};

*/

int main () 
{
    string s="Hardbansh";
    cout<<"Max occured element is : " <<maxOccChar(s)<<endl;
    cout<<"Max occured element is : " <<getMaxOccChar(s)<<endl;
    return 0;
}