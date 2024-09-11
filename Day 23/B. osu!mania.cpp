#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    while (n--) {
        int r;
        cin >> r;
        int c = 4;
        char** a = new char*[r];
        for (int i = 0; i < r; i++) {
            a[i] = new char[c];
            for (int j = 0; j < c; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = r - 1; i >= 0; i--) {
            for (int j = 0; j < c; j++) {
                if (a[i][j] == '#') {
                    cout << j + 1 << " ";
                    break;
                }
            }
        }
        cout << endl;

        // Free dynamically allocated memory
        for (int i = 0; i < r; i++) {
            delete[] a[i];
        }
        delete[] a;
    }
    return 0;
}