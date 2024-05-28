#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int size = 5;
    int *arr = new int[size];
    int front = -1;
    int rear = -1;

public:

    void enqueue(int val)
    {
        // queue is full
        if ((rear == (front - 1) % (size - 1)) || (rear == size - 1 && front == 0))
        {
            cout << "Queue is full!" << endl;
            return;
        }
        else if (front == -1)
        { // first element to push
            front = rear = 0;
            arr[rear] = val;
        }
        else if (rear == size - 1 && front != 0)
        { // rear reached at the last block of array
            rear = 0;
            arr[rear] = val;
        }
        else
        { // rear is at the middle of the array somewhere
            rear++;
            arr[rear] = val;
        }
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        arr[front] = -1;
        if (front == rear)
        { // single element present
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    int Front () {
        if (front == -1) {
            return -1;
        }
        return arr[front];
    }

    int Rear () {
        if (front == -1) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty () {
        if (front == -1) {
            return true;
        }
        return false;
    }

    bool isFull () {
        if ((rear == (front - 1) % (size - 1)) || (rear == size - 1 && front == 0))
        {
            return true;
        }
        return false;
    }

};

int main()
{
    Queue q;

    cout << q.Front() << endl;
    cout << q.Rear() << endl;
    if (q.isFull()) {
        cout << "Full!" << endl;
    }
    else {
        cout << "Not Full!" << endl;
    }
    if (q.isEmpty()) {
        cout << "Empty!" << endl;
    }
    else {
        cout << "Not Empty!" << endl;
    }
    q.enqueue(1);
    if (q.isFull()) {
        cout << "Full!" << endl;
    }
    else {
        cout << "Not Full!" << endl;
    }
    if (q.isEmpty()) {
        cout << "Empty!" << endl;
    }
    else {
        cout << "Not Empty!" << endl;
    }
    q.enqueue(2);
    cout << q.Rear() << endl;

    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.Front() << endl; 
    cout << q.Rear() << endl; 

    if (q.isFull()) {
        cout << "Full!" << endl;
    }
    else {
        cout << "Not Full!" << endl;
    }

    return 0;
}