#ifndef _SORT
#define _SORT

#include <vector>

void insertionSort(std::vector<int> &);

void bubbleSort(std::vector<int> &);

int partition(std::vector<int> &, int, int);
void quickSort(std::vector<int> &, int, int);
void quickSort(std::vector<int> &);

void merge(std::vector<int> &, int, int, int);
void mergeSort(std::vector<int> &, int, int);
void mergeSort(std::vector<int> &);

void heapSort(std::vector<int> &);
void swapHeap(std::vector<int> &, int, int);
void downHeap(std::vector<int> &, int, int);

#endif
