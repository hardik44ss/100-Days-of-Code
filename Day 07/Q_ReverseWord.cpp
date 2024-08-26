#include <iostream>
#include <vector>
using namespace std;

vector<char> rev_Word(vector<char> &chars) {
    int n = chars.size();
    int e = 0;

    while (e < n) {
        int s = e;

        // Find the end of the current word
        while (e < n && chars[e] != ' ') {
            e++;
        }

        int st = s;
        int end = e - 1;
        while (st < end) {// Reverse the current word
            swap(chars[st], chars[end]);
            st++;
            end--;
        }

        e++; // Move to the start of the next word
    }

    return chars;
}

int main() {
    vector<char> chars = {'T', 'h', 'e', ' ', 'q', 'u', 'i', 'c', 'k', ' ', 'b', 'r', 'o', 'w', 'n', ' ', 'f', 'o', 'x'};
    
    vector<char> result = rev_Word(chars);
    
    for (char c : result) {
        cout << c;
    }
    cout << endl;

    return 0;
}
