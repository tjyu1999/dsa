#pragma once
#include <vector>


namespace sort {
    template <typename T>
    void insertion_sort(std::vector<T> &arr) {
        for (int i = 0; i < arr.size(); i++) {
            T temp = arr[i];
            int j = i - 1;

            while (j >= 0 && temp < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = temp;
        }
    }
}