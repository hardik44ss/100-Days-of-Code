#include<iostream>
using namespace std;

int getSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    /*
    int n; 
    cin >> n;
    int arr[n]; // static memory allocated
    // stack memory used : If input is larger than stack memory, it produces an error
    */

    /*
    Memory: Stack, Heap
    Static Allocation: Stack memory
    For assigning variable memory, we use HEAP
    ---------Dynamic memory: Heap---------------
    */
    int n;
    cout << "Enter size: ";
    cin >> n;

    int *arr = new int[n];
    //  *ptr = Stack memory : 8 bytes (x64 bit)
    //  new int = Heap memory : 5*4 bytes (x64 bit)
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);
    cout << "Sum of elements: " << ans << endl;

    delete[] arr;
    //Manually delete the memory in Dynamic memory allocation 
    //Static memory allocation automatically deletes the memory

    return 0;
}
