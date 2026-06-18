#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include "sort.hpp"


static std::vector<int>arr1 = {1, 2, 3};
static std::vector<int>arr2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
static std::vector<int>arr3 = {-1999, -2026, 7777, 3, 2, 1, -10};
static std::vector<float>arr4 = {3.14f, 1.59f, 2.6535f, 89793.f};
static std::vector<float>arr5 = {1.01f, 1.0001f, -0.123f, -0.12345f, -0.00789f, -0.007f};

template <typename T, typename SortFunc>
static bool test_case(std::vector<T> arr, SortFunc sort_func) {
    auto expect = arr;
    std::sort(expect.begin(), expect.end());
    sort_func(arr);
    return expect == arr;
}

template <typename SortFunc>
static void test_sort(const std::string &name, SortFunc sort_func) {
    bool pass = true;

    pass &= test_case(arr1, sort_func);
    pass &= test_case(arr2, sort_func);
    pass &= test_case(arr3, sort_func);
    pass &= test_case(arr4, sort_func);
    pass &= test_case(arr5, sort_func);
    std::cout << name << (pass ? "PASS\n" : "FAIL\n");
}

int main() {
    test_sort("insertion sort\t", [](auto &arr){sort::insertion_sort(arr);});
    test_sort("quick sort\t", [](auto &arr){sort::quick_sort(arr);});
    test_sort("merge sort\t", [](auto &arr){sort::merge_sort(arr);});

    return 0;
}