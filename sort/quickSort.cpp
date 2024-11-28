#include <vector>
#include "sort.h"

int partition(std::vector<int> &nums, int start, int end) {
    int pivot = nums[end];
    int i = start;
    
    for (int j = start; j < end; j++) {
        if (nums[j] <= pivot)
            std::swap(nums[i++], nums[j]);
    }
    std::swap(nums[i], nums[end]);
    
    return i;
}

void quickSort(std::vector<int> &nums, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(nums, start, end);
        
        quickSort(nums, start, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, end);
    }
}

void quickSort(std::vector<int> &nums) {
    quickSort(nums, 0, nums.size() - 1);
}
