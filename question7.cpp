# include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class StackLL {
    Node* top;
public:
    StackLL() : top(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (!top) return;
        Node* del = top;
        top = top->next;
        delete del;
    }

    int peek() {
        return top ? top->data : -1;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    StackLL stack;
    stack.push(10);
    stack.push(20);
    cout << "Top element: " << stack.peek() << endl; // Output: 20
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl; // Output: 10
    return 0;
}