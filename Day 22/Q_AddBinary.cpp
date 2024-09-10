//67 Add two binary : LeetCode
#include<iostream>
#include<string>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = 0;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        sum += carry;
        carry = sum / 2;
        sum = sum % 2;
        result = to_string(sum) + result;
    }
    return result;
}
int main (){
    string a = "1101010101";
    string b = "1010101010";
    cout<<addBinary(a,b);
}