#ifndef _STACK
#define _STACK

#include <iostream>
#include <stdexcept>

class Stack {
private:
    int *st;
    int capacity;
    int _top;

    void doubleCapacity() {
        capacity *= 2;
        int *st_new = new int [capacity];

        for (int i = 0; i < capacity / 2; ++i)
            st_new[i] = st[i];

        delete[] st;
        st = st_new;
    }
    
    bool full() const {
        return _top == capacity - 1;
    }

public:
    Stack(int c) : capacity(c), _top(-1) {
        st = new int [capacity];
    }

    ~Stack() {
        delete[] st;
    }

    bool empty() const {
        return _top == -1;
    }

    int size() const {
        return _top + 1;
    }

    int top() {
        if (empty())
            throw std::runtime_error("Stack is empty.");

        return st[_top];
    }

    void push(const int &x) {
        if (full())
            doubleCapacity();

        st[++_top] = x;
    }

    void pop() {
        if (empty())
            throw std::runtime_error("Stack is empty.");

        --_top;
    }
};

#endif
