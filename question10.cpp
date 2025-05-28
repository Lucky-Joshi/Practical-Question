#include <iostream>
#include <list>
using namespace std;

class QueueLL {
    list<int> q;
public:
    void enqueue(int val) {
        q.push_back(val);
    }

    void dequeue() {
        if (!q.empty()) q.pop_front();
    }

    int peek() {
        return q.empty() ? -1 : q.front();
    }

    bool isEmpty() {
        return q.empty();
    }
};

int main() {
    QueueLL q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl; // 10

    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl; // 20

    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.peek() << endl;
        q.dequeue();
    }

    cout << "Queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}