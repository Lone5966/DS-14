#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Prefix to Infix Conversion
string prefixToInfix(string prefix) {
    stack<string> s;
    reverse(prefix.begin(), prefix.end());

    for (char c : prefix) {
        if (isalpha(c)) {
            s.push(string(1, c));
        } else if (isOperator(c)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string exp = "(" + op1 + c + op2 + ")";
            s.push(exp);
        }
    }

    return s.top();
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Infix to Postfix Conversion
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (char c : infix) {
        if (isalpha(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Postfix Evaluation
int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else if (isOperator(c)) {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();

            switch (c) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
            }
        }
    }

    return s.top();
}

int main() {
    int choice;
    string expression;

    do {
        cout << "Menu:\n";
        cout << "1. Prefix to Infix Conversion\n";
        cout << "2. Infix to Postfix Conversion\n";
        cout << "3. Postfix Evaluation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Prefix Expression: ";
                cin >> expression;
                cout << "Converted Infix Expression: " << prefixToInfix(expression) << endl;
                break;

            case 2:
                cout << "Enter Infix Expression: ";
                cin >> expression;
                cout << "Converted Postfix Expression: " << infixToPostfix(expression) << endl;
                break;

            case 3:
                cout << "Enter Postfix Expression: ";
                cin >> expression;
                cout << "Postfix Evaluation Result: " << evaluatePostfix(expression) << endl;
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
        cout << endl;
    } while (choice != 4);

    return 0;
}
