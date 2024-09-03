#include <iostream>
using namespace std;


inline int square(int x) {       // Inline function definition
    return x * x;
}
inline int max(int a, int b) {    // A more complex inline function
    return (a > b) ? a : b;
}
// Function with a loop (not suitable for inlining, but used for demonstration)
inline void printNumbers(int n) {
    for (int i = 1; i <= n; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int num = 5;
    cout << "Square of " << num << " is: " << square(num) << endl;

    int a = 10, b = 20;
    cout<< "Max of " << a << " and " << b << " is: " << max(a, b) << endl;
    
    printNumbers(10);

    return 0;
}


/*---------------Benifits----------------
    -Readablity
    -Memory management
*/