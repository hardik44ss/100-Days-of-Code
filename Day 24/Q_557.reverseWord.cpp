#include <iostream>

using namespace std;

void reverse(string &st, int s, int e)
{
    while (s < e)
    {
        swap(st[s++], st[e--]);
    }
}

string reverseWords(string st)
{
    int s = 0;
    int e = 0;
    while (s < st.length())
    {
        e = s;
        while (e < st.length() && st[e] != ' ')
        {
            e++;
        }
        reverse(st, s, e - 1);
        s = e + 1;
    }
    return st;
}

int main()
{
    string s;
    getline(cin, s);
    cout << reverseWords(s) << endl;
    return 0;
}