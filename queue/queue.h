#ifndef _QUEUE
#define _QUEUE

#include <iostream>
#include <stdexcept>

class Queue {
private:
    int *q;
    int capacity;
    int _front;
    int _back;

    void doubleCapacity() {
        capacity *= 2;
        int *q_new = new int [capacity];
        int j = -1;
        
        for (int i = _front + 1; i <= _back; ++i)
            q_new[++j] = q[i];

        _front = -1;
        _back = j;
        delete[] q;
        q = q_new;
    }
    
    bool full() const {
        return _back == capacity - 1;
    }

public:
    Queue(int c) : capacity(c), _front(-1), _back(-1) {
        q = new int [capacity];
    }

    ~Queue() {
        delete[] q;
    }

    bool empty() const {
        return _front == _back;
    }

    int size() const {
        return _back - _front;
    }

    int front() {
        if (empty())
            throw std::runtime_error("Queue is empty.");

        return q[_front + 1];
    }
    
    int back() {
        if (empty())
            throw std::runtime_error("Queue is empty.");

        return q[_back];
    }

    void push(const int &x) {
        if (full())
            doubleCapacity();

        q[++_back] = x;
    }

    void pop() {
        if (empty())
            throw std::runtime_error("Queue is empty.");

        ++_front;
    }
};

#endif
