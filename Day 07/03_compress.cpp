#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars)
{
    int i = 0; //Trvesing the char array
    int ansIndex = 0;
    int n = chars.size();
    while (i < n)
    {
        int j = i + 1;
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }
        chars[ansIndex++] = chars[i];
        int count = j - i;
        if (count > 1)
        {
            string cnt = to_string(count);
            cout<<cnt<<endl;
            for (char ch : cnt) //string ko char m convert
            {
                chars[ansIndex++] = ch;
                //string converted string into new array
            }
        }
        i = j;
    }
    return ansIndex;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int newLength = compress(chars);
    // Output the compressed characters
    for (int i = 0; i < newLength; i++) {
        cout << chars[i]<<" ,";
    }
    cout << endl;

    cout << "Compressed length: " << newLength << endl;
    return 0;
}