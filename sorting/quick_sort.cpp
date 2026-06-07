/*
 * Time complexity
 *   Best:    O(nlog(n))
 *   Average: O(nlog(n))
 *   Worst:   O(n^2)
 *
 * Space complexity
 *   Best:    O(log(n))
 *   Average: O(log(n))
 *   Worst:   O(n)
 */


#include <iostream>
#include <algorithm>
#include <vector>


namespace sorting {
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
    void quick_sort(std::vector<T> &arr, const int low, const int high) {
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

template <typename T>
static bool test(std::vector<T>arr) {
    std::vector<T> ref =arr;
    std::sort(ref.begin(), ref.end());
    sorting::quick_sort(arr);
    return ref ==arr;
}

int main() {
    bool pass = true;
    std::vector<int>arr1 = {1, 2};
    std::vector<int>arr2 = {2, 1};
    std::vector<int>arr3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int>arr4 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<float>arr5 = {-3.14f, -1.59f, 2.6535f, 89793.f};

    pass &= test<int>(arr1);
    pass &= test<int>(arr2);
    pass &= test<int>(arr3);
    pass &= test<int>(arr4);
    pass &= test<float>(arr5);
    std::cout << (pass ? "PASS\n" : "FAIL\n");

    return 0;
}