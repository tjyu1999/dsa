#include <iostream>
#include <stdexcept>

class Stack {
private:
    int *st;
    int capacity;
    int front;

    void doubleCapacity() {
        capacity *= 2;
        int *st_new = new int [capacity];

        for (int i = 0; i < capacity / 2; ++i)
            st_new[i] = st[i];

        delete[] st;
        st = st_new;
    }

public:
    Stack(int c) : capacity(c), front(-1) {
        st = new int [capacity];
    }

    ~Stack() {
        delete[] st;
    }

    bool empty() const {
        return front == -1;
    }

    int size() const {
        return front + 1;
    }

    int top() {
        if (empty())
            throw std::runtime_error("Stack is empty.");

        return st[front];
    }

    void pop() {
        if (empty())
            throw std::runtime_error("Stack is empty.");

        --front;
    }

    void push(const int &x) {
        if (top == capacity - 1)
            doubleCapacity();

        st[++top] = x;
    }
};
