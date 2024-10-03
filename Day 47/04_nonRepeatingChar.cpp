#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

string firstNonRepeatingChar(string A) {
    unordered_map<char , int> count;
	 queue<int> q;
	string ans = "";
	
	for(int i =0 ;i<A.length() ; i++){
	    
	    char ch = A[i];
	    count[ch]++;
	    
	    q.push(ch);
	    
	    while(!q.empty()){
	        if(count[q.front()]>1){
	            q.pop();
	        }else{
	            ans.push_back(q.front());
	            break;
	        }
	    }
        if(q.empty()) ans.push_back('#');

    }
    return ans;
}

int main () 
{
    string A = "aabb";
    cout<<firstNonRepeatingChar(A);
    
    return 0;
}