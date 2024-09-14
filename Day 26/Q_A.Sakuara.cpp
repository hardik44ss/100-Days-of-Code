#include<iostream>
#include<vector>
using namespace std;

class Sakurako
{
    public:
    int a, b;
    vector<int> arr;
    Sakurako(int a, int b)
    {
        this->a = a;
        this->b = b;
        for(int i = 1; i <= a; i++)
        {
            arr.push_back(1);
        }
        for(int i = 1; i <= b; i++)
        {
            arr.push_back(2);
        }
    }
    bool solve()
    {
        if(a&1 || (a == 0 && b%2 != 0)){
            return false;
        }else if(a == 0 && b%2 == 0){
            return true;
        }
        
        int sum = a + b*2;
        if(sum%2 != 0){
            return false;
        }else{
            return true;
        }        
    }
};

int main () 
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        Sakurako s(a, b);
       
        if(s.solve()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}