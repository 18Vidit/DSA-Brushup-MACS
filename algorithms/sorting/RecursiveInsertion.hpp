#ifndef RECURSIVE_INSERTION_HPP
#define RECURSIVE_INSERTION_HPP

#include <iostream>
#include <vector>

using namespace std;

/*
 * ALGORITHM: Insertion Sort (Recursive)
 * USE CASE: Demonstrating recursion logic for insertion.
 * TIME COMPLEXITY: O(N^2)
 * SPACE COMPLEXITY: O(N) - Due to recursive call stack.
 * CONSTRAINTS: Risk of Stack Overflow on very large arrays.
 */

inline void recursiveInsertionLogic(vector<int>& arr, int n, long long& iters) {
    // Base case: array of size 1 is already sorted
    if (n <= 1) return;
    // Sort first n-1 elements
    recursiveInsertionLogic(arr, n - 1, iters);
    // Insert the last element at its correct position in sorted array
    int last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last) {
        iters++;
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
    if (j == n - 2) iters++;
}
// Wrapper for main.cpp
inline void insertionSortRecursive(vector<int>& arr, long long& iters) {
    recursiveInsertionLogic(arr, arr.size(), iters);
}

#endif