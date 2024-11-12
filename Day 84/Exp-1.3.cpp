/*
- This code demonstrates and compares the performance of different sorting algorithms on arrays of varying sizes.

Best Sorting Technique: 
- Merge Sort and Quick Sort are the best sorting techniques among the five.
- Both have an average time complexity of O(n log n) and are efficient for large datasets.
- Merge Sort is stable and has a predictable performance, 
  while Quick Sort is faster in practice.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
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
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];
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
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 10000;
    }
    return arr;
}

template <typename Func>
void measureSortingTime(Func sortFunc, vector<int> arr, const string& sortName) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    cout << sortName << " took " << duration.count() << " ms\n";
}

int main() {
    srand(time(0));
    vector<int> sizes = {1000, 5000, 10000, 20000};

    for (int size : sizes) {
        vector<int> arr = generateRandomArray(size);
        cout << "Array of size " << size << ":\n";
        measureSortingTime(bubbleSort, arr, "Bubble Sort");
        measureSortingTime(insertionSort, arr, "Insertion Sort");
        measureSortingTime(selectionSort, arr, "Selection Sort");
        measureSortingTime([](vector<int>& a) { mergeSort(a, 0, a.size() - 1); }, arr, "Merge Sort");
        measureSortingTime([](vector<int>& a) { quickSort(a, 0, a.size() - 1); }, arr, "Quick Sort");
        cout << "------------------------------------\n";
    }
    return 0;
}
/*
Array of size 1000:
Bubble Sort took 15.646 ms
Insertion Sort took 0 ms
Selection Sort took 13.005 ms
Merge Sort took 0 ms
Quick Sort took 0 ms
------------------------------------
Array of size 5000: 
Bubble Sort took 319.127 ms
Insertion Sort took 130.639 ms
Selection Sort took 136.808 ms
Merge Sort took 9.603 ms
Quick Sort took 2.42 ms
------------------------------------
Array of size 10000:
Bubble Sort took 1302.05 ms
Insertion Sort took 307.163 ms
Selection Sort took 463.773 ms
Merge Sort took 10.34 ms
Quick Sort took 3.589 ms
------------------------------------
Array of size 20000:
Bubble Sort took 4181.2 ms
Insertion Sort took 976.927 ms
Selection Sort took 1384.71 ms
Merge Sort took 18.937 ms
Quick Sort took 6.984 ms
------------------------------------
*/
