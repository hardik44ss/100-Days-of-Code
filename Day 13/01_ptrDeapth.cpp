#include<iostream>
#include<vector>
using namespace std;

int main () 
{
    int arr[10]={2,4,6,8,10,12,14,16,18,20};
    cout<<"Address arr : "<<arr<<endl;
    cout<<"Address arr[0] : "<<&arr[0]<<endl;

    cout<<"\nValue at *arr : "<<*arr<<endl;
    cout<<"Value at *arr+1 : "<<*arr+1<<endl;
    cout<<"Value at *(arr+1) : "<<*(arr+1)<<endl;
    cout<<"Value at *(arr)+1 : "<<*(arr)+1<<endl<<endl;

    //Printing address at every index using for loop 

    for(int i=0;i<10;i++){
        cout<<"Value at arr["<<i<<"] : "<<*(i+arr)<<endl;
        //=>  i[arr] = *(i+arr)
        cout<<"Address at arr["<<i<<"] : "<<&arr[i]<<endl;
    }//32 bit : so memory increasing by 4 bytes

    // arr = arr+1 : Give error

    //Size dekhte h x64 bit
    int temp[10];
    cout<<"\nSize of temp : "<<sizeof(temp)<<endl;//40
    cout<<"Size of *temp : "<<sizeof(*temp)<<endl;//4
    cout<<"Size of &temp : "<<sizeof(&temp)<<endl;//8
    //Adress : temp = &temp[0] = &temp

    int *ptr =&temp[0];
    //Address of ptr and temp[0] is different

    cout<<"Size of ptr : "<<sizeof(ptr)<<endl;  //8
    cout<<"Size of *ptr: "<<sizeof(*ptr)<<endl; //4
    cout<<"Size of &ptr : "<<sizeof(&ptr)<<endl;//8






    return 0;
}