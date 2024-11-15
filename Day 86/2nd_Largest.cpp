//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Using a set to handle duplicates
        set<int> uniqueElements(arr.begin(), arr.end());

        // If there are less than 2 unique elements, return -1
        if (uniqueElements.size() < 2) {
            return -1;
        }

        // Priority queue (min-heap) to find the top two largest unique elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : uniqueElements) {
            minHeap.push(num);
            // Maintain the size of the heap as 2
            if (minHeap.size() > 2) {
                minHeap.pop();
            }
        }

        // At this point, the root of the heap contains the second largest unique element
        return minHeap.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends