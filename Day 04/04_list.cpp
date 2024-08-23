#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    // 1. Initialization
    list<int> lst = {1, 2, 3, 4, 5};

    // 2. Accessing front and back elements
    cout << "Front element: " << lst.front() << endl;
    cout << "Back element: " << lst.back() << endl;

    // 3. Adding elements to the front and back
    lst.push_front(0);
    lst.push_back(6);
    cout << "List after push_front(0) and push_back(6): ";
    for (int elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    // 4. Removing elements from the front and back
    lst.pop_front();
    lst.pop_back();
    cout << "List after pop_front() and pop_back(): ";
    for (int elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    // 5. Inserting elements at a specific position
    auto it = lst.begin();
    advance(it, 2); // Move iterator to the 3rd position
    lst.insert(it, 10);
    cout << "List after inserting 10 at the 3rd position: ";
    for (int elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    // 6. Erasing elements at a specific position
    it = lst.begin();
    advance(it, 2); // Move iterator to the 3rd position
    lst.erase(it);
    cout << "List after erasing the element at the 3rd position: ";
    for (int elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    // 7. Removing specific elements by value
    lst.remove(3);  // Removes all elements with value 3
    cout << "List after removing all elements with value 3: ";
    for (int elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    // 8. Reversing the list
    lst.reverse();
    cout << "List after reversing: ";
    for (int elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    // 9. Sorting the list
    lst.sort();
    cout << "List after sorting: ";
    for (int elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    // 10. Merging two lists
    list<int> lst2 = {7, 8, 9};
    lst.merge(lst2);  // Merges lst2 into lst and sorts the combined list
    cout << "List after merging with another list: ";
    for (int elem : lst) {
        cout << elem << " ";
    }
    cout << endl;

    // 11. Clearing the list
    lst.clear();
    cout << "List after clearing: ";
    if (lst.empty()) {
        cout << "List is empty" << endl;
    } else {
        for (int elem : lst) {
            cout << elem << " ";
        }
    }

    return 0;
}
