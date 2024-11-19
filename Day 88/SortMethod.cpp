/* Best Sorting Technique: 
- Merge Sort and Quick Sort are the best sorting techniques among the five.
- Both have an average time complexity of O(n log n) and are efficient for large datasets.
- Merge Sort is stable and has a predictable performance, while Quick Sort is faster in practice.

*/
#include <bits/stdc++.h>
using namespace std;
/*
Sorting Algorithms:

1. Bubble Sort:
   - Bubble Sort is a simple comparison-based sorting algorithm.
   - It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
   - This process is repeated until the list is sorted.
   - Time Complexity: O(n^2) in the worst and average cases.
   - Space Complexity: O(1) (in-place sorting).
   - Stability: Stable (does not change the relative order of equal elements).
*/



void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*
2. Insertion Sort:
   - Insertion Sort is a simple comparison-based sorting algorithm.
   - It builds the final sorted array one item at a time.
   - It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.
   - Time Complexity: O(n^2) in the worst and average cases.
   - Space Complexity: O(1) (in-place sorting).
   - Stability: Stable (does not change the relative order of equal elements).
*/

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

/*
3. Merge Sort:
   - Merge Sort is a divide-and-conquer algorithm.
   - It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
   - Time Complexity: O(n log n) in all cases (worst, average, and best).
   - Space Complexity: O(n) (requires additional space for merging).
   - Stability: Stable (does not change the relative order of equal elements).
*/

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/*
4. Quick Sort:
   - Quick Sort is a divide-and-conquer algorithm.
   - It picks an element as a pivot and partitions the given array around the picked pivot.
   - Time Complexity: O(n log n) on average, O(n^2) in the worst case.
   - Space Complexity: O(log n) (in-place sorting).
   - Stability: Not stable (may change the relative order of equal elements).
*/

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/*
5. Selection Sort:
   - Selection Sort is a simple comparison-based sorting algorithm.
   - It divides the input list into two parts: the sublist of items already sorted and the sublist of items remaining to be sorted.
   - It repeatedly selects the smallest (or largest) element from the unsorted sublist, swaps it with the leftmost unsorted element, and moves the sublist boundaries one element to the right.
   - Time Complexity: O(n^2) in the worst and average cases.
   - Space Complexity: O(1) (in-place sorting).
   - Stability: Not stable (may change the relative order of equal elements).
*/

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl<<endl;
}

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
    return arr;
}

int main() {
    srand(time(0));

    vector<int> sizes = {5 , 10 , 50 , 1000};

    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);

        cout << "Original array of size " << size << ":\n";
        printArray(arr);

        vector<int> bubbleSorted = arr;
        bubbleSort(bubbleSorted);
        cout << "Bubble Sorted:\n";
        printArray(bubbleSorted);

        vector<int> insertionSorted = arr;
        insertionSort(insertionSorted);
        cout << "Insertion Sorted:\n";
        printArray(insertionSorted);

        vector<int> selectionSorted = arr;
        selectionSort(selectionSorted);
        cout << "Selection Sorted:\n";
        printArray(selectionSorted);

        vector<int> mergeSorted = arr;
        mergeSort(mergeSorted, 0, size - 1);
        cout << "Merge Sorted:\n";
        printArray(mergeSorted);

        vector<int> quickSorted = arr;
        quickSort(quickSorted, 0, size - 1);
        cout << "Quick Sorted:\n";
        printArray(quickSorted);

        cout << "------------------------------------\n";
    }

    return 0;
}
/*
Original array of size 10:
77 86 1 79 75 10 90 37 77 58 

Bubble Sorted:
1 10 37 58 75 77 77 79 86 90 

Insertion Sorted:
1 10 37 58 75 77 77 79 86 90 

Selection Sorted: 
1 10 37 58 75 77 77 79 86 90 

Merge Sorted:
1 10 37 58 75 77 77 79 86 90 

Quick Sorted:
1 10 37 58 75 77 77 79 86 90 

------------------------------------
*/
