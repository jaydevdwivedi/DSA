#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int size = 100001;
    int front;
    int rear;

public:
    Queue()
    {
        arr = new int[size];
        rear = 0;
        front = 0;
    }

    void enqueue (int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear++] = data;
    }

    void dequeue () {

        if (front == rear) {
            cout << "Queue is empty." << endl;
            return;
        }

        arr[front] = -1;
        front++;

        if (front == rear) {
            front = rear = 0;
        }
    }

    bool isEmpty () {
        if (front == rear) {
            return 1;
        }
        return 0;
    }

    int queueSize() {
        return rear-1;
    }

    int queueFront() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    int queueRear() {
        if (front == rear) {
            cout << "Queue is empty ";
            return -1;
        }
        return arr[rear-1];
    }
};

int main()
{
    Queue *q = new Queue();

    q->enqueue(1);
    q->dequeue();
    cout << q->queueRear() << endl;
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(0);

    cout << q->queueFront() << endl;

    if (q->isEmpty()) {
        cout << "Queue is empty." << endl;
    }
    else {
        cout << "Not empty." << endl;
    }

    return 0;
}