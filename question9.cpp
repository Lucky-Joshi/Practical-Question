#include <iostream>
using namespace std;

class QueueArray {
    int arr[100], front, rear;
public:
    QueueArray() : front(-1), rear(-1) {}

    void enqueue(int val) {
        if (rear == 99) return;
        if (front == -1) front = 0;
        arr[++rear] = val;
    }

    void dequeue() {
        if (front == -1 || front > rear) return;
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    int peek() {
        return (front != -1 && front <= rear) ? arr[front] : -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }
};

int main() {
    QueueArray queue;
    queue.enqueue(10);
    queue.enqueue(20);
    cout << "Front element: " << queue.peek() << endl; // Output: 10
    queue.dequeue();
    cout << "Front element after dequeue: " << queue.peek() << endl; // Output: 20
    return 0;
}