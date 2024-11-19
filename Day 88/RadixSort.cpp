/*
Radix Sort:

Theory:
- Radix Sort is a non-comparative sorting algorithm.
- It sorts numbers by processing individual digits.
- It processes digits from the least significant digit (LSD) to the most significant digit (MSD).

Steps:
1. Find the maximum number to determine the number of digits.
2. Use counting sort to sort elements based on each digit, starting from the least significant digit to the most significant digit.
3. Repeat the process for each digit.

Time Complexity:
- Best, Average, and Worst Case: O(d * (n + b))
  where d is the number of digits, n is the number of elements, and b is the base (e.g., 10 for decimal numbers).

Space Complexity:
- O(n + b), where n is the number of elements and b is the base.

Stability:
- Radix Sort is stable (does not change the relative order of equal elements).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// A utility function to get the maximum value in arr[]
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// A function to do counting sort of arr[] according to the digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // output array
    int count[10] = {0}; // count array to store count of occurrences of digits (0 to 9)

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed.
    // exp is 10^i where i is the current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main() {
    // Predefined input array
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform Radix Sort
    radixSort(arr);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Expected Output:
Original array: 170 45 75 90 802 24 2 66 
Sorted array: 2 24 45 66 75 90 170 802 
*/