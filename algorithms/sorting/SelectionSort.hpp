#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

/*
 * ALGORITHM: Selection Sort
 * USE CASE: When memory write operations (swaps) are extremely costly, as this 
 * algorithm makes the absolute minimum number of swaps (O(N) swaps).
 * TIME COMPLEXITY: O(N^2) - For Best, Average, and Worst cases. It always 
 * scans the entire unsorted portion.
 * SPACE COMPLEXITY: O(1) - Sorts in place.
 * CONSTRAINTS: Very slow for large datasets. It is also an "unstable" sort 
 * (it might change the relative order of equal elements).
 */

inline void selectionSort(vector<int>& arr, long long& iters) {
    int n = arr.size();
    // Move the boundary of the unsorted subarray one by one
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            iters++; // Track every single comparison
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        // We only do a swap if the minimum isn't already in the right place
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

#endif