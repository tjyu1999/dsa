#include <iostream>
#include <stdexcept>
#include "queue.h"

int main() {    
    try {
        Queue q(3);
        q.push(10);
        q.push(20);
        q.push(30);
        std::cout << "\nst.front() = " << q.front() << std::endl;
        std::cout << "st.back() = " << q.back() << std::endl;
        q.pop();
        std::cout << "st.front() = " << q.front() << std::endl;
        q.push(40);
        std::cout << "st.back() = " << q.back() << std::endl;
        q.pop();
        q.pop();
        q.pop();
        std::cout << "st.empty() = " << q.empty() << std::endl;
        std::cout << "st.size() = " << q.size() << std::endl;
        q.pop();
    }
    catch(const std::runtime_error &e) {
        std::cerr << "Queue Exception: " << e.what() << std::endl;
    }
        
    return 0;
}
