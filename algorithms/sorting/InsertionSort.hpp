#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <iostream>
#include <vector>

using namespace std;

/*
 * ALGORITHM: Insertion Sort (Iterative)
 * USE CASE: Best for small datasets or arrays that are already "nearly sorted."
 * It is a "Stable" and "In-place" sort.
 * TIME COMPLEXITY: 
 * - Worst/Average: O(N^2)
 * - Best: O(N) (If the array is already sorted)
 * SPACE COMPLEXITY: O(1)
 * CONSTRAINTS: Not efficient for large datasets compared to Merge/Quick sort.
 */

inline void insertionSortIterative(vector<int>& arr, long long& iters) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            iters++; // Track every shift/comparison
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        // If the while loop didn't run, we still performed one comparison
        if (j == i - 1) iters++; 
    }
}

#endif