#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "sort.h"
#include "utils.h"

typedef void (*sortFuncPtr) (std::vector<int> &);

sortFuncPtr getFunc(int n) {
    switch (n) {
        case 1:
            std::cout << "Insertion sort: ";
            return insertionSort;
        
        case 2:
            std::cout << "Bubble sort   : ";
            return bubbleSort;
            
        case 3:
            std::cout << "Quick sort    : ";
            return quickSort;
            
        case 4:
            std::cout << "Merge sort    : ";
            return mergeSort;
            
        case 5:
            std::cout << "Heap sort     : ";
            return heapSort;
        
        default:
            std::cerr << "Invalid case." << std::endl;
            return nullptr;
    }
}

void defaultTest(sortFuncPtr sortingFunc) {
    int len = 5 + rand() % 16;
    std::vector<int> nums = randomVec(len);
    std::vector<int> ans = nums;
    std::sort(ans.begin(), ans.end());
    
    sortingFunc(nums);
    assert(nums == ans);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        for (int n = 1; n <= 5; ++n) {
            sortFuncPtr sortFunc = getFunc(n);
            defaultTest(sortFunc);
            
            std::cout << "Test passed." << std::endl;
        }
    }
    
    else {
        std::vector<int> nums;
        for (int i = 1; i < argc; ++i)
            nums.push_back(std::stoi(argv[i]));
        
        for (int n = 1; n <= 5; ++n) {
            sortFuncPtr sortFunc = getFunc(n);
            sortFunc(nums);
            printVec(nums);
        }
    }
    
    return 0;
}
