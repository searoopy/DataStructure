#pragma once
#include <stack>

template <typename T>
class Queue {
public:
    void enqueue(T element) {
        inbox.push(element);
    }

    T dequeue() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        T front = outbox.top();
        outbox.pop();
        return front;
    }

    T peek() {
        if (outbox.empty()) {
            while (!inbox.empty()) {
                outbox.push(inbox.top());
                inbox.pop();
            }
        }
        return outbox.top();
    }

    bool isEmpty() {
        return inbox.empty() && outbox.empty();
    }

private:
    std::stack<T> inbox;
    std::stack<T> outbox;
};
