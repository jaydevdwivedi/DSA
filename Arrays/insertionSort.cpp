#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr)
{

    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int n, int arr[]){
    
    for(int i = 1; i<n; i++) {
        int temp = arr[i];
        int j = i-1;
        for(; j>=0; j--) {
            
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            }
            else {
                break;
            }
            
        }
        //copy temp value
        arr[j+1] = temp;  
    } 
}

int main()
{
    int arr[] = {2, 1, 4, 5};

    insertionSort(4, arr);
    printArray(arr);
    return 0;
}