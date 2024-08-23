#include <iostream>
#include <set>
using namespace std;

int main() {
    // 1. Initialization
    set<int> s = {1, 2, 3, 4, 5};

    // 2. Inserting elements
    s.insert(6);
    s.insert(3); // Duplicate element, will not be inserted

    // 3. Size of the set
    cout << "Size of the set: " << s.size() << endl;

    // 4. Checking if an element exists (using find)
    int element = 4;
    if (s.find(element) != s.end()) {
        cout << element << " exists in the set." << endl;
    } else {
        cout << element << " does not exist in the set." << endl;
    }

    // 5. Erasing elements by value
    s.erase(2);
    cout << "Set after erasing 2: ";
    for (int elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    // 6. Iterating over the set
    cout << "All elements in the set: ";
    for (int elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    // 7. Clearing the set
    s.clear();
    cout << "Set after clearing, size: " << s.size() << endl;

    // 8. Inserting elements in a loop
    for (int i = 1; i <= 5; ++i) {
        s.insert(i * 10);
    }
    cout << "Set after inserting elements in a loop: ";
    for (int elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    // 9. Using lower_bound and upper_bound
    auto lower = s.lower_bound(20);
    auto upper = s.upper_bound(40);
    cout << "Lower bound of 20: " << (lower != s.end() ? to_string(*lower) : "not found") << endl;
    cout << "Upper bound of 40: " << (upper != s.end() ? to_string(*upper) : "not found") << endl;

    // 10. Checking if the set is empty
    if (s.empty()) {
        cout << "Set is empty." << endl;
    } else {
        cout << "Set is not empty." << endl;
    }

    // 11. Merging two sets
    set<int> s2 = {50, 60, 70};
    s.insert(s2.begin(), s2.end());
    cout << "Set after merging with another set: ";
    for (int elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
