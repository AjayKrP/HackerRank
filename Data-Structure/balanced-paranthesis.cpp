#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(string str) {
    stack<char >s;
    for (char i : str) {
        if (i == '(' || i == '{' || i == '[') {
            s.push(i);
        } else if (i == ')' || i == '}' || i == ']') {
            if (s.empty() || (s.top() != '(' && i == ')') || (s.top() != '{' && i == '}') || (s.top() != '[' && i == ']')) {
                return false;
            } else{
                s.pop();
            }
        }
    }
    return s.empty();
}

int main() {
    string s;
    cin >> s;
    if (isBalanced(s)) {
        cout << "Balanced";
    } else{
        cout << "Not Balanced";
    }
}
