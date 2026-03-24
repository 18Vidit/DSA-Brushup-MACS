#ifndef KADANE_HPP
#define KADANE_HPP

#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

/*
 * ALGORITHM: Kadane's Algorithm
 * USE CASE: Finding the maximum contiguous subarray sum within a 1D array. 
 * Often used in financial analysis (maximum profit over a period) 
 * or genomic sequence analysis.
 * TIME COMPLEXITY: O(N) - We only traverse the array exactly once.
 * SPACE COMPLEXITY: O(1) - We only use two integer variables for tracking.
 * CONSTRAINTS: Handles arrays with all negative numbers perfectly (it will 
 * return the single least negative number).
 */

inline int kadaneMaxSubArray(const vector<int>& arr, long long& iters) {
    // Edge case for empty array
    if (arr.empty()) return 0; 
    int max_so_far = arr[0];
    int current_max = arr[0];
    for (int i = 1; i < (int)arr.size(); i++) {
        iters++; // Tracking iterations for the main.cpp profiler
        // THE INTUITION: 
        // Do we add the current element to our running sequence, 
        // or is the current element so big that we should ditch the old 
        // sequence and start a brand new one right here?
        current_max = max(arr[i], current_max + arr[i]);
        max_so_far = max(max_so_far, current_max);
    }

    return max_so_far;
}

#endif