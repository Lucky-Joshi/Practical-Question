#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;
    for (char ch : expr) {
        if (isdigit(ch)) s.push(ch - '0'); // Convert character to integer
        else {
            if (s.size() < 2) {
                cerr << "Error: insufficient operands for operator '" << ch << "'." << endl;
                return 0;
            }
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (ch) {
                case '+': s.push(a + b); break;
                case '-': s.push(a - b); break;
                case '*': s.push(a * b); break;
                case '/':
                    if (b == 0) {
                        cerr << "Error: division by zero." << endl;
                        return 0;
                    }
                    s.push(a / b);
                    break;
                default:
                    cerr << "Error: unknown operator '" << ch << "'." << endl;
                    return 0;
            }
        }
    }
    return s.top();
}

int main() {
    string expr = "23*54*+";
    int result = evaluatePostfix(expr);
    cout << "Result of postfix expression: " << result << endl; // Output: 26
    return 0;
}