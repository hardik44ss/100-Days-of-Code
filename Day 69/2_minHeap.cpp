#include<iostream>
using namespace std;

class Heap
{
    int arr[100];
    int size;
    public:
        Heap(){
            arr[0]=-1;
            size = 0;
        }

    void insert(int data)
    {
        int index = ++size;
        arr[index] = data;

        while(index>1){
            int parent = index/2;
            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                break;
            }
        }
    }   // Time : O(log N)

    // //Deletion : It means deleting root node
    void deleteMin(){
        if(size==0)
        {
            cout<<"No element present"<<endl;
            return ;
        }
        
        arr[1] = arr[size];

        size = size - 1;
        int i = 1;
        int leftIndex,rightIndex;
        while(i<size)
        {
            leftIndex = 2 * i;
            rightIndex = 2*i + 1;
            if(leftIndex <= size && arr[leftIndex]<arr[i] && arr[leftIndex]< arr[rightIndex])
            {
                swap(arr[leftIndex],arr[i]);
                i = leftIndex;
            }
            else if(rightIndex <= size && arr[rightIndex]<arr[i] && arr[leftIndex]> arr[rightIndex])
            {
                swap(arr[rightIndex],arr[i]);
                i = rightIndex;
            }
            else
            return;
        }
    }  // Time : O(log N)

    void print() {
        for(int i=1; i<=size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl<<endl;
    }
};

void printArr(int* arr , int size) {
    for(int i=1; i<=size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl<<endl;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] > arr[left]) {
        largest = left;
    }
            
    if(right <= n && arr[largest] > arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main () 
{
    Heap h;
    h.insert(10);
    h.insert(15);
    h.insert(20);
    h.insert(25);
    h.insert(45);
    h.insert(12);
    h.insert(60);

    h.print();

    h.deleteMin();
    h.print();

    h.deleteMin();
    h.print();

    //Heapifying a giver array  ( 0-based indexing )
    int arr[] = {0, 10, 20, 15, 25, 45, 12, 60};
    int n = sizeof(arr)/sizeof(arr[0]) - 1;

    cout<<"Before heapify : ";
    printArr(arr, n);

    for(int i=n/2; i>=1; i--) {
        heapify(arr, n, i);
    }

    cout<<"After heapify : ";
    printArr(arr, n);

    return 0;
}