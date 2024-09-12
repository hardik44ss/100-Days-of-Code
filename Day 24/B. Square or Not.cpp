#include <iostream>
#include <string>
using namespace std;

void printAns(string s, int n) {
    int len = s.length();
    if (len != n * n) {
        cout << "No" << endl;
        return;
    }

    // Initialize the matrix
    char arr[n][n];
    int k = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[k++];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if the element is on the border
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                if (arr[i][j] == '0') {
                    cout << "No" << endl;
                    return;
                }
            } 
            // If it's an inner element, it should not contain '1'
            else {
                if (arr[i][j] == '1') {
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }

    cout << "Yes" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        printAns(s, n);
    }
    return 0;
}
