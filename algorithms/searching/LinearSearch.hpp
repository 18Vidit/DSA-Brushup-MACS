#ifndef LINEAR_SEARCH_HPP
#define LINEAR_SEARCH_HPP

#include <iostream>
#include <vector>

using namespace std;

/*
 * ALGORITHM: Linear Search
 * USE CASE: Finding an element in an UNSORTED array or a very small dataset.
 * TIME COMPLEXITY: O(N) - Worst case, we must check every single element.
 * SPACE COMPLEXITY: O(1) - No extra memory is needed.
 * CONSTRAINTS: Very slow for large datasets. However, it requires absolutely 
 */

inline int linearSearch(const vector<int>& arr, int target, long long& iters) {
    for (int i = 0; i < (int)arr.size(); i++) {
        iters++; // Track every time we make a comparison
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}

#endif