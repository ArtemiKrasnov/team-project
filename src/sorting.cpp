#include "sorting.h"
#include <algorithm>

void Sorter::bubbleSort(std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); ++i)
        for (size_t j = 0; j < arr.size() - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

static int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; ++j)
        if (arr[j] < pivot) std::swap(arr[++i], arr[j]);
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

static void quickRec(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickRec(arr, low, pi - 1);
        quickRec(arr, pi + 1, high);
    }
}

void Sorter::quickSort(std::vector<int>& arr) {
    if (!arr.empty()) quickRec(arr, 0, arr.size() - 1);
}