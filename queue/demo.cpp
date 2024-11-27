#include <iostream>
#include <stdexcept>
#include "queue.h"

int main() {    
    try {
        Queue q(3);
        q.push(1);
        q.push(2);
        q.push(3);
        std::cout << "q.front() = " << q.front() << std::endl;
        std::cout << "q.back() = " << q.back() << std::endl;
        q.pop();
        std::cout << "q.front() = " << q.front() << std::endl;
        q.push(4);
        std::cout << "q.back() = " << q.back() << std::endl;
        q.pop();
        q.pop();
        q.pop();
        std::cout << "q.empty() = " << q.empty() << std::endl;
        std::cout << "q.size() = " << q.size() << std::endl;
        q.pop();
    }
    catch(const std::runtime_error &e) {
        std::cerr << "Queue Exception: " << e.what() << std::endl;
    }    
    
    return 0;
}
