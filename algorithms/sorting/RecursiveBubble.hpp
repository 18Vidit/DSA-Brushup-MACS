#ifndef RECURSIVE_BUBBLE_HPP
#define RECURSIVE_BUBBLE_HPP

#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

/*
 * ALGORITHM: Bubble Sort (Recursive)
 * USE CASE: Demonstrating how iterative loops can be translated to recursion.
 * TIME COMPLEXITY: O(N^2)
 * SPACE COMPLEXITY: O(N) - Due to the function call stack overhead.
 * CONSTRAINTS: Will cause a Stack Overflow on large arrays because it requires 
 * N recursive calls in the worst case. Not suitable for large datasets.
 */

inline void recursiveBubbleLogic(vector<int>& arr, int n, long long& iters) {
    // Base case: If array size is 1, it's sorted
    if (n == 1) return;
    int swaps = 0;
    // One pass of bubble sort. After this, the largest element is at the end.
    for (int i = 0; i < n - 1; i++) {
        iters++; // Track comparisons
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
            swaps++;
        }
    }
    // Optimization: If no swaps occurred, it's sorted
    if (swaps == 0) return;
    // Recursively call for the rest of the array (n - 1)
    recursiveBubbleLogic(arr, n - 1, iters);
}

// Wrapper function to match our testing format in main.cpp
inline void bubbleSortRecursive(vector<int>& arr, long long& iters) {
    recursiveBubbleLogic(arr, arr.size(), iters);
}

#endif