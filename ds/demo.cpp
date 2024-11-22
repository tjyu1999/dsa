#include <iostream>
#include <stdexcept>
#include "stack.h"
#include "queue.h"

int main() {
    try {
        Stack st(3);
        st.push(10);
        st.push(20);
        st.push(30);
        std::cout << "st.top() = " << st.top() << std::endl;
        st.pop();
        std::cout << "st.pop() = " << st.top() << std::endl;
        st.push(40);
        std::cout << "st.top() = " << st.top() << std::endl;
        st.pop();
        st.pop();
        st.pop();
        std::cout << "st.empty() = " << st.empty() << std::endl;
        std::cout << "st.size() = " << st.size() << std::endl;
        st.pop();
    }
    catch(const std::runtime_error &e) {
        std::cerr << "Stack Exception: " << e.what() << std::endl;
    }
    
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
