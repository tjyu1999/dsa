#include <iostream>
#include <vector>
#include <time.h>
#include "utils.h"

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printVec(const std::vector<int> &nums) {
    for (auto n : nums)
        std::cout << n << " ";
    std::cout << std::endl;
}

std::vector<int> randomVec(const int &len) {
    srand(unsigned(time(0)));
    std::vector<int> nums;
    
    for (int i = 0; i < len; ++i)
        nums.push_back(rand() % 100);
    
    return nums;
}
