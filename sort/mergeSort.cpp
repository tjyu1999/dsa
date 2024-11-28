#include <vector>
#include "sort.h"

void merge(std::vector<int> &nums, int start, int mid, int end) {
    int i = 0;
    int l = start;
    int r = mid + 1;
    std::vector<int> merged(end - start + 1);
    
    while (l <= mid && r <= end) {
        if (nums[l] < nums[r])
            merged[i++] = nums[l++];
        else
            merged[i++] = nums[r++];
    }
    
    while (l <= mid)
        merged[i++] = nums[l++];
    while (r <= end)
        merged[i++] = nums[r++];
    
    for (int j = 0; j < i; ++j)
        nums[start + j] = merged[j];
}

void mergeSort(std::vector<int> &nums, int start, int end) {    
    if (start < end) {
        int mid = (start + end) / 2;
        
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}

void mergeSort(std::vector<int> &nums) {
    mergeSort(nums, 0, nums.size() - 1);
}
