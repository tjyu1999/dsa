#include <vector>
#include "sort.h"
#include "utils.h"

void bubbleSort(std::vector<int> &nums) {
    bool swapped;
    
    do {
        swapped = false;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                swapped = true;
                swap(nums[i - 1], nums[i]);
            }
        }
    } while (swapped);
}
