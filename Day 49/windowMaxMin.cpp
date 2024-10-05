#include<iostream>
#include<queue>
using namespace std;

/*  {2 , 5 , -1 , 7 , 4 , 6 ,3 } k = 4
1st : {2,5,-1,7}  max + min = 7 -1 = 6
2nd : {5,-1,7,4}  max + min = 7 -1 = 6
3rd : {-1,7,4,6}  max + min = 7 -1 = 6
4th : {7,4,6,3}   max + min = 7 +3 = 10
Ans : 6 + 6 + 6 + 10 = 28
*/
int solve(int *arr , int n , int k){
    int sum = 0;
    deque<int> maxQ;
    deque<int> minQ;
    int i = 0;
    for(;i<k;i++){
        while(!maxQ.empty() && arr[i]>=arr[maxQ.back()]){
            maxQ.pop_back();
        }
        while(!minQ.empty() && arr[i]<=arr[minQ.back()]){
            minQ.pop_back();
        }
        maxQ.push_back(i);
        minQ.push_back(i);
    }
    for(;i<n;i++){
        sum += arr[maxQ.front()] + arr[minQ.front()];
        while(!maxQ.empty() && maxQ.front()<=i-k){
            maxQ.pop_front();
        }
        while(!minQ.empty() && minQ.front()<=i-k){
            minQ.pop_front();
        }
        while(!maxQ.empty() && arr[i]>=arr[maxQ.back()]){
            maxQ.pop_back();
        }
        while(!minQ.empty() && arr[i]<=arr[minQ.back()]){
            minQ.pop_back();
        }
        maxQ.push_back(i);
        minQ.push_back(i);
    }
    sum += arr[maxQ.front()] + arr[minQ.front()];
    return sum;
}

int main () 
{
    int arr[7] = {2 , 5 , -1 , 7 , 4 , 6 ,3};   
    cout<<solve(arr , 7 , 4);
    return 0;
}