#include <bits/stdc++.h>
using namespace std;


void pointer (int** p) {
    // p = p + 1; // No change
    // *p = *p + 1;
    **p = **p + 1;
}

void update(int *ptr) {
    ptr = ptr + 1;
}

int main() {

    int a = 10;
    int *p = &a;

    cout << p << endl;
    update(p);
    cout << a << endl;
    cout << p << endl;

    // Double pointer
    int i = 5;
    int *p1 = &i;
    int **p2 = &p1;
    cout << "Before: " << endl;
    cout << i << endl;
    cout << &i << endl;
    cout << p1 << endl;
    cout << &p1 << endl;
    cout << p2 << endl;
    cout << *p1 << endl;
    cout << **p2 << endl;
    cout << *p2 << endl;
    cout << &i << endl << endl;

    pointer(p2);

    cout << "After: " <<endl;
    cout << i << endl;
    cout << &i << endl;
    cout << p1 << endl;
    cout << &p1 << endl;
    cout << p2 << endl;
    cout << *p1 << endl;
    cout << **p2 << endl;
    cout << *p2 << endl;
    cout << &i << endl;

    // cout << &i << endl;
    // cout << p1 << endl;
    // cout << &p1 << endl;
    // cout << p2 << endl;
    // int a = 0;
    // int *p = &a;

    // cout << p << endl;
    // cout << *p << endl;

    // cout << &a << endl;
    // cout << sizeof(p) << endl;

    // int x = &a;
    
    // int arr[3] = {20, 43, 73};


    // arr[i] = (arr + i)
    // i[arr] = (arr + 1)

    // cout << arr << endl;
    // cout << &arr[0] << endl;
    // cout << arr[0] << endl;
    // cout << &arr << endl;

    // cout << *arr << endl;
    // cout << *(arr + 1) << endl;
    // cout << *(arr) + 1 << endl;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << arr[i] << endl;
    // }

    // cout << endl;

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << i[arr] << endl;
    // }


    // int arr[5];
    // char ch[6] = "abcde";

    // cout << arr << endl;
    // cout << ch << endl;

    return 0;
}