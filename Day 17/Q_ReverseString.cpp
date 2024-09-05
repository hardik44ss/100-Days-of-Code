#include <bits/stdc++.h> 
void reverse(string &str,int i, int j ){
	if(i>j)
		return;
	// Write your code here.
	swap(str[i],str[j]);
	i++;
	j--;
	reverse(str,i,j);
}
string reverseString(string str,int i=0)
{
	reverse(str,0,str.size()-1);	
	return str;
}