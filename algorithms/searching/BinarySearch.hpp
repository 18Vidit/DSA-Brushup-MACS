#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP

#include <iostream>
#include <vector>

using namespace std;

/*
 * ALGORITHM: Binary Search (Iterative & Recursive)
 * USE CASE: Finding an element in a SORTED array.
 * TIME COMPLEXITY: O(log N) - We cut the search space in half every iteration.
 * SPACE COMPLEXITY: 
 * - Iterative: O(1) (No extra memory)
 * - Recursive: O(log N) (Due to the function call stack)
 * CONSTRAINTS: The array MUST be sorted beforehand, otherwise it fails completely.
 */

// 1. ITERATIVE BINARY SEARCH
inline int binarySearchIterative(const vector<int>& arr, int target, long long& iters) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        iters++; // Track iterations
       
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// 2. RECURSIVE BINARY SEARCH
// Helper function that actually does the recursion
inline int binarySearchRecHelper(const vector<int>& arr, int left, int right, int target, long long& iters) {
    if (left > right) return -1; // Base case: not found

    iters++; // Track iterations
    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid;

    if (arr[mid] < target) {
        // Search right half
        return binarySearchRecHelper(arr, mid + 1, right, target, iters);
    } else {
        // Search left half
        return binarySearchRecHelper(arr, left, mid - 1, target, iters);
    }
}

// Wrapper function to keep the main.cpp clean
inline int binarySearchRecursive(const vector<int>& arr, int target, long long& iters) {
    return binarySearchRecHelper(arr, 0, arr.size() - 1, target, iters);
}

#endif