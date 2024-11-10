//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        int i = 0, j = 0;
        int n1 = a.size(), n2 = b.size();

        while (i < n1 && j < n2) {
            // Skip duplicates in array `a`
            if (i > 0 && a[i] == a[i - 1]) {
                i++;
                continue;
            }
            // Skip duplicates in array `b`
            if (j > 0 && b[j] == b[j - 1]) {
                j++;
                continue;
            }

            if (a[i] < b[j]) {
                ans.push_back(a[i++]);
            } else if (a[i] > b[j]) {
                ans.push_back(b[j++]);
            } else {
                ans.push_back(a[i]);
                i++;
                j++;
            }
        }

        // Process remaining elements of `a`, skipping duplicates
        while (i < n1) {
            if (i == 0 || a[i] != a[i - 1]) {
                ans.push_back(a[i]);
            }
            i++;
        }

        // Process remaining elements of `b`, skipping duplicates
        while (j < n2) {
            if (j == 0 || b[j] != b[j - 1]) {
                ans.push_back(b[j]);
            }
            j++;
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends