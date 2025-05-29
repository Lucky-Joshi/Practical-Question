# include <iostream>
using namespace std;

class StackArray {
    int arr[100], top;
public:
    StackArray() : top(-1) {} // Constructor to initialize the stack

    void push(int val) {
        if (top == 99) return; // Stack is full, cannot push
        arr[++top] = val; // Push value onto the stack at the top position
    }

    void pop() {
        if (top == -1) return; // Stack is empty
        top--; // Remove the top element by decrementing the top index
    }

    int peek() {
        if (top == -1) return -1; // Stack is empty
        return arr[top]; // Return the top element without removing it
    }

    bool isEmpty() { 
        return top == -1; // Check if the stack is empty
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