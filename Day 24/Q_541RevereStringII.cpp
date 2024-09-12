#include <iostream>
using namespace std;

void reverse(string &st, int s, int e)
{
    while (s < e)
    {
        swap(st[s++], st[e--]);
    }
}
string reverseStr(string st, int k)
{
    int s = 0;
    int e = st.length() - 1;
    while (s < e)
    {
        if (s + k > e)
        {
            reverse(st, s, e);
            return st;
        }
        else
        {
            reverse(st, s, s + k - 1);
        }
        s = s + 2 * k;
    }
    return st;
}

int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << reverseStr(s, k) << endl;

    return 0;
}