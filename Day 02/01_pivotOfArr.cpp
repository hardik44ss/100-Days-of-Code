#include<iostream>
using namespace std;

//Finding pivot element in an array 
int pivot(int arr[], int size) {
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;
    while (s < e) {
        if (arr[mid] >= arr[0]) {
            s = mid + 1;
        } else {
            e = mid;  
        }
        mid = s + (e - s) / 2;
    }
    return s;  
}

int main() {
    int arr[10] = {7,8,9,11,1,2,3,4,5,6};
    cout << "Pivot element index : " << pivot(arr, 10) << endl;
    return 0;

}