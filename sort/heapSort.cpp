#include <vector>
#include "sort.h"

void swapHeap(std::vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i]  = nums[j];
    nums[j]  = temp;
}

void downHeap(std::vector<int> &nums, int i, int size) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    
    if (l < size && nums[l] > nums[max])
        max = l;
    if (r < size && nums[r] > nums[max])
        max = r;
    
    if (max != i) {
        swapHeap(nums, i, max);
        downHeap(nums, max, size);
    }
}

void heapSort(std::vector<int> &nums) {
    int size = nums.size();
    
    for (int i = size / 2; i >= 0 ; --i)
        downHeap(nums, i, size);
    
    for (int i = nums.size() - 1; i >= 0; --i) {
        swapHeap(nums, 0, i);
        downHeap(nums, 0, i);
    }
}
