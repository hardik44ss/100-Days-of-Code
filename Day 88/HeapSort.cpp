/*
Heap Sort:

Theory:
- Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure.
- It is similar to selection sort where we first find the maximum element and place it at the end. We repeat the same process for the remaining elements.

Steps:
1. Build a max heap from the input data.
2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of the heap by one. Finally, heapify the root of the tree.
3. Repeat step 2 while the size of the heap is greater than 1.

Time Complexity:
- Best, Average, and Worst Case: O(n log n)

Space Complexity:
- O(1) (in-place sorting)

Stability:
- Heap Sort is not stable (may change the relative order of equal elements).
*/

#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted with node i which is an index in arr[]. n is the size of the heap
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i; // left = 2*i
    int right = 2 * i + 1; // right = 2*i + 1

    // If left child is larger than root
    if (left <= n && arr[largest] < arr[left]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right <= n && arr[largest] < arr[right]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]); // Swap root with largest
        heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

// Main function to do heap sort
void heapSort(int arr[], int size) {
    // Build heap (rearrange array)
    for (int i = size / 2; i > 0; i--) {
        heapify(arr, size, i);
    }

    // One by one extract an element from heap
    while (size > 1) {
        // Move current root to end
        swap(arr[1], arr[size]);

        // Reduce heap size
        size--;

        // Call max heapify on the reduced heap
        heapify(arr, size, 1);
    }
}

int main() {
    int arr[6] = {-1, 54, 53, 55, 50, 52}; // Array with a dummy element at index 0
    int size = 5; // Size of the heap (excluding the dummy element)
    
    // Print the unsorted array
    cout << "Unsorted array: ";
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Build the heap
    for (int i = size / 2; i > 0; i--) {
        heapify(arr, size, i);
    }

    // Print the heap
    cout << "Heap: ";
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Perform heap sort
    heapSort(arr, size);

    // Print the sorted array
    cout << "Sorted array (Heap Sort): ";
    for (int i = 1; i <= size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}