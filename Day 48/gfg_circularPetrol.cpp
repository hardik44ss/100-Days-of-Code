#include<iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[] , int n){
    int kami = 0 ;
    int bal = 0 ;
    int start = 0 ;
    for(int i = 0 ; i < n ; i++){
        bal += p[i].petrol - p[i].distance ;
        if(bal < 0){
            kami += bal ;
            bal = 0 ;
            start = i + 1 ;
        }
    }

    if(bal + kami >= 0){
        return start ;
    }
    return -1 ;
}

int main () 
{
    int n;
    cin >> n;
    petrolPump arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].petrol;
        cin >> arr[i].distance;
    }

    return 0;
}