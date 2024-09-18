#include<iostream>
#include<vector>
#include<climits> // Add this line to include the <climits> header file
using namespace std;

int thirdMaximum(vector<int> nums){
    long long int max1 = LLONG_MIN;
    long long int max2 = LLONG_MIN;
    long long int max3 = LLONG_MIN;

    for(int n: nums){
        if(n > max1){
            max3 = max2;
            max2 = max1;
            max1 = n;
        }
        else if(n > max2 && n < max1){
            max3 = max2;
            max2 = n;
        }
        else if(n > max3 && n < max2){
            max3 = n;
        }
    }
    return max3 != LLONG_MIN ? max3 : max1;
    //Return max3 if all three are distinct otherwise return max1
}

int main () 
{
    vector<int> arr = {2,1,2,1,1,2,2,1};
    cout << thirdMaximum(arr) << endl;
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << thirdMaximum(arr2) << endl;

    return 0;
}