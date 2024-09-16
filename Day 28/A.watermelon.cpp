#include<iostream>
#include<vector>
using namespace std;

bool divide(int n) {
    if(n%2 == 0 && n != 2) {
        return true;
    }
    return false;
}

int main () 
{
    int n;
    cin >> n;
    if(divide(n)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}