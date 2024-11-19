/*
Bucket Sort:

Theory:
- Bucket Sort is a sorting algorithm that divides the elements into several groups called buckets.
- Each bucket is then sorted individually, either using another sorting algorithm or by applying bucket sort again.
- Finally, the sorted buckets are combined to form the final sorted array.

Steps:1
1. Create empty buckets.
2. Distribute the elements of the array into the buckets.
3. Sort each bucket.
4. Combine the sorted buckets to get the final sorted array.

Time Complexity:
- Best Case: O(n + k) where n is the number of elements and k is the number of buckets.
- Average Case: O(n + k)
- Worst Case: O(n^2) when all elements end up in the same bucket.

Space Complexity:
- O(n + k), where n is the number of elements and k is the number of buckets.

Stability:
- Bucket Sort is stable if the sorting algorithm used for sorting the buckets is stable.

Note:
- Bucket Sort works well when the input is uniformly distributed over a range.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform bucket sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    if (n <= 0) return;

    // 1. Create empty buckets
    vector<vector<float>> buckets(n);

    // 2. Scatter: Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; // Index in bucket 
        buckets[bucketIndex].push_back(arr[i]);
    }

    // 3. Sort each bucket
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // 4. Gather: Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (size_t j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    // Predefined input array
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};

    cout << "Original array: ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Perform Bucket Sort
    bucketSort(arr);

    // Output the sorted array
    cout << "Sorted array (Bucket Sort): ";
    for (float num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Expected Output:
Original array: 0.897 0.565 0.656 0.1234 0.665 0.3434 
Sorted array (Bucket Sort): 0.1234 0.3434 0.565 0.656 0.665 0.897 
*/