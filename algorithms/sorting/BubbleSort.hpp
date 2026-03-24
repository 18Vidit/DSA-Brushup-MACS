#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

/*
 * ALGORITHM: Bubble Sort (Iterative)
 * USE CASE: Educational purposes or when the array is nearly sorted already.
 * TIME COMPLEXITY: 
 * - Worst/Average: O(N^2)
 * - Best: O(N) (If the array is already sorted, thanks to the 'swapped' flag)
 * SPACE COMPLEXITY: O(1) - Sorts in place.
 * CONSTRAINTS: Extremely slow for large, completely unsorted datasets.
 */

inline void bubbleSortIterative(vector<int>& arr, long long& iters) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        // The last 'i' elements are already in place, so we don't check them
        for (int j = 0; j < n - i - 1; j++) {
            iters++; // Track comparisons
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Optimization: If no two elements were swapped by the inner loop, 
        // the array is completely sorted. Break early.
        if (!swapped) break;
    }
}

#endif