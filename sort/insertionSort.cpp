#include <vector>
#include "sort.h"

void insertionSort(std::vector<int> &nums) {
    for (int i = 1; i < (int) nums.size(); ++i) {
        int key = nums[i];
        int j = i - 1;
        
        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            --j;
        }
        
        nums[j + 1] = key;
    }
}