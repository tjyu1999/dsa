class Stack {
private:
    int *st;
    int capacity;
    int top;

public:
    Stack(int c) : capacity(c) {
        st = new int [capacity];
    }

    ~Stack() {
        delete[] st;
    }

    bool empty() const {
        
    }

    void pop() {
        
    }

    void push(const int) {
        
    }
};
