#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>  // for accumulate
using namespace std;

int main() {
    // 1. Initialization
    array<int, 5> arr = {1, 2, 3, 4, 5};

    // 2. Accessing elements
    cout << "First element: " << arr[0] << endl;
    cout << "Second element using at(): " << arr.at(1) << endl;

    // 3. Size of the array
    cout << "Size of the array: " << arr.size() << endl;

    // 4. Checking if array is empty
    cout << "Is array empty? " << boolalpha << arr.empty() << endl;

    // 5. Front and back elements
    cout << "Front element: " << arr.front() << endl;
    cout << "Back element: " << arr.back() << endl;

    // 6. Fill the array with a specific value
    arr.fill(10);
    cout << "Array after filling with 10: ";
    for (int elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    // 7. Sorting the array
    arr = {5, 2, 3, 1, 4};
    sort(arr.begin(), arr.end());
    cout << "Array after sorting: ";
    for (int elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    // 8. Finding an element
    auto it = find(arr.begin(), arr.end(), 3);
    if (it != arr.end()) {
        cout << "Element 3 found at index: " << distance(arr.begin(), it) << endl;
    } else {
        cout << "Element 3 not found" << endl;
    }

    // 9. Sum of elements
    int sum = accumulate(arr.begin(), arr.end(), 0);
    cout << "Sum of elements: " << sum << endl;

    // 10. Swap two arrays
    array<int, 5> arr2 = {6, 7, 8, 9, 10};
    arr.swap(arr2);
    cout << "Array after swapping with arr2: ";
    for (int elem : arr) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
