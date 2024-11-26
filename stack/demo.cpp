#include <iostream>
#include <stdexcept>
#include "stack.h"

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

    return 0;
}
