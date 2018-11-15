#include <stack>
#include <iostream>

using namespace std;

class Queue {
    stack<int> s1, s2;
public:
    Queue();
    void push(int data) {

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        s1.push(data);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        if (!s1.empty()) {
            s1.pop();
        }
    }

    int top() {
        if (!s1.empty()) {
            return s1.top();
        }
    }
};

Queue::Queue() = default;

int main() {
    auto * q = new Queue;
    q->push(5);
    q->push(6);
    q->push(7);
    cout << q->top();
}
