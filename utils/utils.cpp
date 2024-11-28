#include <iostream>
#include <vector>
#include <time.h>
#include "utils.h"

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printVec(std::vector<int> &nums) {
    for (auto n : nums)
        std::cout << n << " ";
    std::cout << std::endl;
}

void randomVec(std::vector<int> &nums) {
    srand(unsigned(time(0)));
    
    for (int i = 0; i < (int) nums.size(); ++i)
        nums[i] = rand() % 100;
}
