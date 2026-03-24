#ifndef DFS_HPP
#define DFS_HPP

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// [doing this for the first time]
/*
 * ALGORITHM: Depth-First Search (DFS)
 * USE CASE: Exploring all possible paths in a graph/tree. Excellent for cycle 
 * detection, solving mazes, and topological sorting.
 * TIME COMPLEXITY: O(V + E) - Where V is vertices (nodes) and E is edges.
 * SPACE COMPLEXITY: O(V) - For the recursion call stack and visited tracking.
 * CONSTRAINTS: Can easily cause a Stack Overflow on massive, deep graphs due 
 * to recursion limits.
 */

// Helper function to handle the actual recursion
inline void dfsRecursiveHelper(int node, const unordered_map<int, vector<int>>& graph, 
                               unordered_map<int, bool>& visited, vector<int>& result, long long& iters) {
    // 1. Mark current node as visited and add to result
    visited[node] = true;
    result.push_back(node);
    iters++; // Track iterations
    // 2. Check all neighbors
    if (graph.count(node)) {
        for (int i = 0; i < graph.at(node).size(); i++) {
            int neighbor = graph.at(node)[i];
            
            // 3. If neighbor is unvisited, immediately dive deep into it
            if (!visited[neighbor]) {
                dfsRecursiveHelper(neighbor, graph, visited, result, iters);
            }
        }
    }
}
// Wrapper function to keep main.cpp clean and initialize the visited map
inline vector<int> dfsTraversal(int startNode, const unordered_map<int, vector<int>>& graph, long long& iters) {
    vector<int> result;
    unordered_map<int, bool> visited;
    
    dfsRecursiveHelper(startNode, graph, visited, result, iters);
    
    return result;
}

#endif