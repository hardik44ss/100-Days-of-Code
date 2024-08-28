#include <iostream>
#include <vector>
using namespace std;

// Homework : segmented sieve
int countPrimes(int n)
{
    int cnt = 0;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = false;
            }
        }
    }
    return cnt;
}//Complexity : O(n*log(logn ))  --> n/2 + n/3 + n/5 ......


//Sieve of Eratosthanos
int main()
{
    int n;
    cin>>n;
    cout<<"Prime  number till n : "<<countPrimes(n);
    return 0;
}
//----------------------------------------------------
bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int countPrimesTLE(int n)
{
    int cnt = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            cnt++;
        }
    }
    return cnt;
} //Complexity : O(n*n)