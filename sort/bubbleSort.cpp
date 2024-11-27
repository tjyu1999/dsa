/* time complexity: O(n^2) */

#include <iostream>
#include <vector>
#include "../utils.h"

void bubbleSort(vector<int> &nums, int start, int end){
    bool swapped;
    
    do {
        swapped = false;
        
        for (int i = start; i <= end; ++i) {
            if (nums[i - 1] > nums[i]) {
                swapped = true;
                swap(nums[i - 1], nums[i]);
            }
        }
    } while(swapped);
}

void bubbleSort(vector<int> &nums){
    bubbleSort(nums, 0, nums.size());
    printVec(&nums);
}
