#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <climits> 

using namespace std;

// [doing this first time][did not understand it fully]

/*
 * ALGORITHM: Dijkstra's Shortest Path
 * USE CASE: Finding the shortest path from a starting node to all other nodes 
 * in a weighted graph (e.g., GPS routing, network routing protocols).
 * TIME COMPLEXITY: O(V + E log V) - Where V is vertices and E is edges. 
 * The log V comes from the Priority Queue (Min-Heap) operations.
 * SPACE COMPLEXITY: O(V + E) - For storing the graph and the distance array.
 * CONSTRAINTS: Fails if the graph has negative weight edges (You would need 
 * Bellman-Ford for that).
 */

// The graph is represented as an Adjacency List: 
// vector index = the node
// pair = {connected_node, weight_of_edge}
inline vector<int> dijkstraShortestPath(int source, const vector<vector<pair<int, int>>>& graph, long long& iters) {
    int n = graph.size();
    
    // Array to store the shortest distance from source to every other node.
    // We initialize everything to "infinity" (INT_MAX).
    vector<int> dist(n, INT_MAX);
    
    // Min-Heap Priority Queue: stores pairs of {current_distance, node}
    // std::greater makes it so the SMALLEST distance is always at the top.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start at the source node
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        iters++; // Tracking iterations for the profiler
        
        int current_dist = pq.top().first;
        int u = pq.top().second; // u is the current node
        pq.pop();

        // Optimization: If we already found a shorter path to this node 
        // earlier, skip processing it again.
        if (current_dist > dist[u]) continue;

        // Check all neighbors of node u
        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i].first;       // The neighbor node
            int weight = graph[u][i].second; // The distance to that neighbor

            // If taking the path through 'u' is shorter than the currently known path to 'v'
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Add the newly found shorter path to the queue
            }
        }
    }
    return dist; // Returns an array of the shortest distances to all nodes
}
#endif