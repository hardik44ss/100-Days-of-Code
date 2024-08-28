#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  
    int i = low + 1;     
    int j = high;         

    while (i <= j) {
        // Move the left index to the right as long as arr[i] <= pivot
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        // Move the right index to the left as long as arr[j] > pivot
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        // Swap elements if i and j are not crossing each other
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot in its correct position
    swap(arr[low], arr[j]);
    return j; // Return the index of the pivot
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Get the partition index
        quickSort(arr, low, pi - 1); // Recursively sort elements before the partition
        quickSort(arr, pi + 1, high); // Recursively sort elements after the partition
    }
}

int main() {
    int arr[] = {1, 3, 4, 5, 32, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);
    
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
