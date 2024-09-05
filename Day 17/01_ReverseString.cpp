#include<iostream>
using namespace std;

string reverse(string str, int i , int j ){
    if(i>j){
        return str;
    }
    swap(str[i],str[j]);
    i++;
    j--;
    return reverse(str,i , j );
}

string reverseString(string  name ){
    int i = 0, j = name.length() - 1;
    return reverse(name,i,j);
}

int main () 
{
    string name = "Hardik";
    cout << "Original String: " << name << endl;
    cout<< "Reversed String " <<reverseString(name )<<endl;
    return 0;
}