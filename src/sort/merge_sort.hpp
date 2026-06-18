#pragma once
#include <vector>


namespace sort {
    template <typename T>
    void merge(std::vector<T> &arr, int l, int m, int r) {
        int i = 0;
        int j = 0;
        int k = l;
        std::vector<T> left(arr.begin() + l, arr.begin() + m + 1);
        std::vector<T> right(arr.begin() + m + 1, arr.begin() + r + 1);

        while (i < (int)left.size() && j < (int)right.size())
            arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];

        while (i < (int)left.size())
            arr[k++] = left[i++];

        while (j < (int)right.size())
            arr[k++] = right[j++];
    }

    template <typename T>
    void merge_sort_internal(std::vector<T> &arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            merge_sort_internal(arr, l, m);
            merge_sort_internal(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }

    template <typename T>
    void merge_sort(std::vector<T> &arr) {
        if (!arr.empty())
            merge_sort_internal(arr, 0, (int)arr.size() - 1);
    }
}