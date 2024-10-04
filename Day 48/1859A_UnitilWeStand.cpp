#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    sort(arr.begin(), arr.end());  // Sort the array

    int min_element = arr[0];  // First element is the minimum after sorting
    int second_order = -1;  // Variable to hold second order statistics
    
    // Find the first element greater than the minimum element
    for (int i = 1; i < n; ++i) {
        if (arr[i] > min_element) {
            second_order = arr[i];
            break;
        }
    }
    
    if (second_order == -1) {
        cout << "NO" << endl;
    } else {
        cout << second_order << endl;
    }
    
    return 0;
}