#include <vector>
#include "sort.h"

void bubbleSort(std::vector<int> &nums) {
    bool swapped;
    
    do {
        swapped = false;
        
        for (int i = 0; i < (int) nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                swapped = true;
                std::swap(nums[i - 1], nums[i]);
            }
        }
    } while(swapped);
}
