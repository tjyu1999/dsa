#include <iostream>
#include <stdexcept>

class Queue {
private:


public:
    Queue() {
        
    }

    ~Queue() {
        
    }

    bool empty() const {
        
    }

    void push(const int &x) {
        
    }

    void pop() {
        if (empty())
            throw std::runtime_error("Queue is empty.");

        ++front;
    }
}
