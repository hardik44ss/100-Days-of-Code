#include <iostream>
#include <vector>
using namespace std;

// Function to reverse a part of the array
void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to rotate the array to the left by d steps
void rotateLeft(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n; // Handle cases where d > n
    if (d == 0) return; // No rotation needed

    // Step 1: Reverse the first d elements
    reverseArray(arr, 0, d - 1);

    // Step 2: Reverse the remaining n-d elements
    reverseArray(arr, d, n - 1);

    // Step 3: Reverse the entire array
    reverseArray(arr, 0, n - 1);
}

// Driver code
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 2; // Number of steps to rotate left

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    rotateLeft(arr, d);

    cout << "Array after rotating left by " << d << " steps: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
