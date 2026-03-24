#ifndef BFS_HPP
#define BFS_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
// [doing for the first time]
/*
 * ALGORITHM: Breadth-First Search (BFS)
 * USE CASE: Traversing or searching tree/graph data structures level by level.
 * Excellent for finding the shortest path in an UNWEIGHTED graph or network.
 * TIME COMPLEXITY: O(V + E) - Where V is vertices (nodes) and E is edges.
 * SPACE COMPLEXITY: O(V) - For the queue and the visited tracking.
 * CONSTRAINTS: Can consume a lot of memory if the graph is extremely wide 
 * (high branching factor) because the queue stores entire levels at once.
 */

inline vector<int> bfsTraversal(int startNode, const unordered_map<int, vector<int>>& graph, long long& iters) {
    vector<int> traversalOrder; // Stores the final output order
    unordered_map<int, bool> visited; // Tracks where we have been
    queue<int> q; // The core data structure for BFS

    // 1. Initialize the start node
    q.push(startNode);
    visited[startNode] = true;
    // 2. Loop until the queue is completely empty
    while (!q.empty()) {
        iters++; // Track iterations for the profiler
        int current = q.front();
        q.pop();
        traversalOrder.push_back(current);
        // 3. Check all neighbors of the current node
        // (Using .count() ensures we don't crash if a node has no outgoing edges)
        if (graph.count(current)) {
            for (int i = 0; i < graph.at(current).size(); i++) {
                int neighbor = graph.at(current)[i];
                // If we haven't seen this neighbor yet, add it to the queue
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark as visited IMMEDIATELY to prevent duplicates
                    q.push(neighbor);
                }
            }
        }
    }

    return traversalOrder;
}

#endif