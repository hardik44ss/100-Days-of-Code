#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // 1. Initialization
    map<int, string> m;

    // 2. Inserting elements (using insert)
    m.insert({1, "one"});
    m.insert({2, "two"});

    // 3. Inserting elements (using operator[])
    m[3] = "three";
    m[4] = "four";

    // 4. Accessing elements
    cout << "Element with key 2: " << m[2] << endl;

    // 5. Size of the map
    cout << "Size of the map: " << m.size() << endl;

    // 6. Checking if a key exists (using count)
    int key = 3;
    if (m.count(key) > 0) {
        cout << "Key " << key << " exists in the map." << endl;
    } else {
        cout << "Key " << key << " does not exist in the map." << endl;
    }

    // 7. Iterating over the map
    cout << "All elements in the map:" << endl;
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 8. Erasing elements by key
    m.erase(2);
    cout << "Map after erasing key 2:" << endl;
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // 9. Finding an element by key
    auto it = m.find(3);
    if (it != m.end()) {
        cout << "Found element with key 3: " << it->second << endl;
    } else {
        cout << "Element with key 3 not found" << endl;
    }

    // 10. Clearing the map
    m.clear();
    cout << "Map after clearing, size: " << m.size() << endl;

    // 11. Inserting multiple elements using a loop
    for (int i = 1; i <= 5; ++i) {
        m[i] = "value" + to_string(i);
    }
    cout << "Map after inserting multiple elements:" << endl;
    for (const auto& pair : m) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
