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

void printMST(const std::vector<std::vector<int>> &mst) {
    for (auto e : mst) {
        for (auto item : e)
            std::cout << item << " ";
            
        std::cout << std::endl;
    }
}

void reverse(std::vector<int> &vec) {
    int l = 0;
    int r = vec.size() - 1;

    while (l < r) {
        swap(vec[l], vec[r]);
        ++l;
        --r;
    }
}
