#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

/*
 * ALGORITHM: Quick Sort
 * USE CASE: The "go-to" general purpose sort. Highly cache-efficient and 
 * usually faster than Merge Sort in practice despite same average complexity.
 * TIME COMPLEXITY: 
 * - Average/Best: O(N log N)
 * - Worst: O(N^2) (Happens if the pivot is always the smallest or largest element)
 * SPACE COMPLEXITY: O(log N) - Due to recursive calls.
 * CONSTRAINTS: Not a "Stable" sort.
 */

// This function takes the last element as pivot and places it correctly
inline int partition(vector<int>& arr, int low, int high, long long& iters) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);    // Index of smaller element
    for (int j = low; j <= high - 1; j++) {
        iters++; // Track comparisons
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
// The recursive function
inline void quickSortLogic(vector<int>& arr, int low, int high, long long& iters) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high, iters);
        // Separately sort elements before and after partition
        quickSortLogic(arr, low, pi - 1, iters);
        quickSortLogic(arr, pi + 1, high, iters);
    }
}
// Wrapper for main.cpp
inline void quickSort(vector<int>& arr, long long& iters) {
    quickSortLogic(arr, 0, arr.size() - 1, iters);
}

#endif