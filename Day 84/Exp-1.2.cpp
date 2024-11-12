/*
Experiment 2: Sorting Arrays Using Different Sorting Algorithms
Course Outcome: 1

Key Points:
- This program demonstrates five sorting algorithms: Bubble Sort, Insertion Sort, Selection Sort, Merge Sort, and Quick Sort.
- It generates arrays of different sizes to test and compare the sorting techniques.
- Sorting Techniques:
  1. Bubble Sort: Repeatedly swaps adjacent elements if they are in the wrong order.
  2. Insertion Sort: Builds a sorted array one item at a time by inserting each element into its correct position.
  3. Selection Sort: Finds the smallest element and places it in the correct position.
  4. Merge Sort: A divide-and-conquer algorithm that divides the array into halves, sorts them, and merges.
  5. Quick Sort: Another divide-and-conquer algorithm that partitions the array around a pivot.

- Results are printed to show the sorted arrays for each sorting method.

Best Sorting Technique: 
- Merge Sort and Quick Sort are the best sorting techniques among the five.
- Both have an average time complexity of O(n log n) and are efficient for large datasets.
- Merge Sort is stable and has a predictable performance, while Quick Sort is faster in practice.

*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

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

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
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

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        while (arr[i] <= pivot && i < high)
            ++i;
        while (arr[j] > pivot)
            --j;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    vector<int> sizes = {10, 20, 50, 100};

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
