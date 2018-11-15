#include <queue>
#include <iostream>
using namespace std;

class Stack{
    queue<int> q1, q2;
public:
    Stack() = default;

    void push(int data) {
        q2.push(data);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            return;
        }
        q1.pop();
    }

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
    }
};

int main() {
    auto *s = new Stack();
    s->push(4);
    s->push(5);
    s->push(7);
    cout << s->top() << endl;
    s->pop();
    cout << s->top() << endl;
    s->push(10);
    cout << s->top();
}
