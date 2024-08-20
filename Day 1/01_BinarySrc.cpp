#include<iostream>
using namespace std;

int binry(int arr[], int n, int target) {
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s <= e) {
        if (arr[mid] == target) {
            return mid;
        } else if (target < arr[mid]) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main () 
{
    int hardik[8]={1,2,3,4,5,6,7,8};
    cout<<"Element present at : "<<binry(hardik,8,5)<<endl;
    cout<<"Element present at : "<<binry(hardik,8,44)<<endl;
    return 0;
}