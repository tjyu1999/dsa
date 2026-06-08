#pragma once
#include <iostream>
#include <vector>


namespace sort {
    template <typename T>
    int partition(std::vector<T> &arr, const int low, const int high) {
        T pivot = arr[high];
        int i = low - 1;
        int j;

        for (j = low; j < high; j++) {
            if (arr[j] <= pivot)
                std::swap(arr[++i], arr[j]);
        }
        
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    template <typename T>
    void quick_sort(std::vector<T> &arr, int low, int high) {
        if (low < high) {
            int p = partition(arr, low, high);

            quick_sort(arr, low, p - 1);
            quick_sort(arr, p + 1, high);
        }
    }

    template <typename T>
    void quick_sort(std::vector<T> &arr) {
        if (!arr.empty())
            quick_sort(arr, 0, (int)arr.size() - 1);
    }
}