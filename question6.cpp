# include <iostream>
using namespace std;

class StackArray {
    int arr[100], top;
public:
    StackArray() : top(-1) {}

    void push(int val) {
        if (top == 99) return;
        arr[++top] = val;
    }

    void pop() {
        if (top == -1) return;
        top--;
    }

    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    StackArray stack;
    stack.push(10);
    stack.push(20);
    cout << "Top element: " << stack.peek() << endl; // Output: 20
    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl; // Output: 10
    return 0;
}