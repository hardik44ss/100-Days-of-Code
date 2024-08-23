#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // for accumulate
using namespace std;

int main() {
    // 1. Initialization
    vector<int> vec = {1, 2, 3, 4, 5};

    // 2. Accessing elements
    cout << "First element: " << vec[0] << endl;
    cout << "Second element using at(): " << vec.at(1) << endl;

    // 3. Size and capacity of the vector
    cout << "Size of the vector: " << vec.size() << endl;
    cout << "Capacity of the vector: " << vec.capacity() << endl;

    // 4. Adding elements (push_back)
    vec.push_back(6);
    cout << "Vector after push_back(6): ";
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    // 5. Removing elements (pop_back)
    vec.pop_back();
    cout << "Vector after pop_back(): ";
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    // 6. Insert elements at a specific position
    vec.insert(vec.begin() + 2, 10);  // Insert 10 at index 2
    cout << "Vector after inserting 10 at index 2: ";
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    // 7. Erase elements from a specific position
    vec.erase(vec.begin() + 2);  // Erase element at index 2
    cout << "Vector after erasing element at index 2: ";
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    // 8. Sorting the vector
    sort(vec.begin(), vec.end());
    cout << "Vector after sorting: ";
    for (int elem : vec) {
        cout << elem << " ";
    }
    cout << endl;

    // 9. Finding an element
    auto it = find(vec.begin(), vec.end(), 3);
    if (it != vec.end()) {
        cout << "Element 3 found at index: " << distance(vec.begin(), it) << endl;
    } else {
        cout << "Element 3 not found" << endl;
    }

    // 10. Sum of elements
    int sum = accumulate(vec.begin(), vec.end(), 0);
    cout << "Sum of elements: " << sum << endl;

    // 11. Clearing the vector
    vec.clear();
    cout << "Vector after clear(): ";
    if (vec.empty()) {
        cout << "Vector is empty" << endl;
    } else {
        for (int elem : vec) {
            cout << elem << " ";
        }
    }

    return 0;
}
