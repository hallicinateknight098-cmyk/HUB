#include <iostream>
#include <stack>
#include <string>
using namespace std;

// checking if parentheses are balanced
bool checkBrackets(const string &expr) {
    stack<char> st;
    for (char ch : expr) {
        if (ch == '(') {
            st.push(ch);
        } else if (ch == ')') {
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

// Returning priority of operator
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Convert infix -> postfix
string toPostfix(const string &expr) {
    stack<char> st;
    string result = "";

    for (char ch : expr) {
        if (isdigit(ch)) {
            result += ch;  // operand goes directly
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        else { // operator
            while (!st.empty() && getPriority(st.top()) >= getPriority(ch)) {
                result += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

// Evaluate postfix expression
int calcPostfix(const string &postfix) {
    stack<int> st;
    for (char ch : postfix) {
        if (isdigit(ch)) {
            st.push(ch - '0'); 
        } else {
            int n2 = st.top(); st.pop();
            int n1 = st.top(); st.pop();
            switch (ch) {
                case '+': st.push(n1 + n2); break;
                case '-': st.push(n1 - n2); break;
                case '*': st.push(n1 * n2); break;
                case '/': st.push(n1 / n2); break;
            }
        }
    }
    return st.top();
}

int main() {
    string expr;
    cout << "Enter infix expression (single-digit numbers only): ";
    cin >> expr;

    if (!checkBrackets(expr)) {
        cout << "Error: Mismatched brackets!" << endl;
        return 0;
    }

    string postfix = toPostfix(expr);
    cout << "Postfix form: " << postfix << endl;

    int answer = calcPostfix(postfix);
    cout << "Final Result: " << answer << endl;

    return 0;
}