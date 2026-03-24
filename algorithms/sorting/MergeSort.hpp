#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <iostream>
#include <vector>

using namespace std;

/*
 * ALGORITHM: Merge Sort
 * USE CASE: Large datasets, linked lists, or when stable sorting is required.
 * TIME COMPLEXITY: 
 * - Best/Average/Worst: O(N log N). Very consistent.
 * SPACE COMPLEXITY: O(N) - It requires a temporary array for merging.
 * CONSTRAINTS: Not "In-place" like QuickSort; it needs extra memory.
 */

// This function merges two sorted sub-arrays back into the original array
inline void merge(vector<int>& arr, int left, int mid, int right, long long& iters) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    // Create temporary arrays
    vector<int> L(n1), R(n2);
    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        iters++; // Track comparisons
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    // Copy remaining elements if any
    while (i < n1) { iters++; arr[k++] = L[i++]; }
    while (j < n2) { iters++; arr[k++] = R[j++]; }
}
// The recursive function
inline void mergeSortLogic(vector<int>& arr, int left, int right, long long& iters) {
    if (left >= right) return; // Base case
    int mid = left + (right - left) / 2;
    // Divide
    mergeSortLogic(arr, left, mid, iters);
    mergeSortLogic(arr, mid + 1, right, iters);
    // Combine (Merge)
    merge(arr, left, mid, right, iters);
}
// Wrapper for main.cpp
inline void mergeSort(vector<int>& arr, long long& iters) {
    mergeSortLogic(arr, 0, arr.size() - 1, iters);
}

#endif