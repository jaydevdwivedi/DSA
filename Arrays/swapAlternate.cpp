#include<bits/stdc++.h>
using namespace std;

void swapAlternate(int arr[], int size) {

    for (int i = 0; i < size; i+=2)
    {
        if (i + 1 < size) {
            swap(arr[i], arr[i + 1]);
        }
    }
}


void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};

    swapAlternate(arr, 6);
    printArray(arr, 6);

    return 0;
}