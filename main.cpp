#include <iostream>
#include <vector>
#include <chrono>   // High-resolution timing
#include <cstdlib>  // Random numbers (rand, srand)
#include <ctime>    // Time for seeding random
#include <algorithm> // Essential for std::sort (used to prep Binary Search)

// DATA STRUCTURE DEMOS
#include "data_structures/LinearStructures.hpp"
#include "data_structures/Maps.hpp"
#include "data_structures/CustomStructures.hpp"

// ALGORITHM SUITE 
#include "algorithms/extras/Kadane.hpp"
#include "algorithms/extras/Dijkstra.hpp"
#include "algorithms/searching/LinearSearch.hpp"
#include "algorithms/searching/BinarySearch.hpp"
#include "algorithms/searching/BFS.hpp"
#include "algorithms/searching/DFS.hpp"
#include "algorithms/sorting/BubbleSort.hpp"
#include "algorithms/sorting/RecursiveBubble.hpp"
#include "algorithms/sorting/SelectionSort.hpp"
#include "algorithms/sorting/InsertionSort.hpp"
#include "algorithms/sorting/RecursiveInsertion.hpp"
#include "algorithms/sorting/MergeSort.hpp"
#include "algorithms/sorting/QuickSort.hpp"

using namespace std;

// Helper: Generates an array of size 'n' with random integers
vector<int> generateRandomArray(int n) {
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; 
    }
    return arr;
}

int main() {
    // Seed the random number generator for unique results every run
    srand((unsigned int)time(0));
    cout << "DSA-Brushup-MACS: Performance Profiler \n";

    // DATA STRUCTURE Operations
    cout << "Abstract Data Structures (Operations) \n";
    runAllLinearDemos();
    runAllMapDemos();
    runAllCustomDemos();
    cout << "\n Data Structure Demos Completed \n\n";


    // GRAPH ALGORITHMS (Fixed Graph Size)
    cout << "Graph Traversal & Shortest Path \n";
    
    // Setup Unweighted Graph for BFS/DFS
    unordered_map<int, vector<int>> unweightedGraph;
    unweightedGraph[0] = {1, 2}; unweightedGraph[1] = {0, 3, 4};
    unweightedGraph[2] = {0, 5}; unweightedGraph[3] = {1};
    unweightedGraph[4] = {1};    unweightedGraph[5] = {2};

    long long gIters = 0;
    vector<int> bfsRes = bfsTraversal(0, unweightedGraph, gIters);
    cout << "BFS Order: "; for(int x : bfsRes) cout << x << " "; cout << " (Iters: " << gIters << ")\n";

    gIters = 0;
    vector<int> dfsRes = dfsTraversal(0, unweightedGraph, gIters);
    cout << "DFS Order: "; for(int x : dfsRes) cout << x << " "; cout << " (Iters: " << gIters << ")\n";

    // Setup Weighted Graph for Dijkstra
    vector<vector<pair<int, int>>> weightedGraph(5);
    weightedGraph[0] = {{1, 10}, {4, 3}}; weightedGraph[1] = {{2, 2}, {4, 4}};
    weightedGraph[4] = {{1, 1}, {2, 8}, {3, 2}}; // Nodes connected to 4
    
    gIters = 0;
    vector<int> dPath = dijkstraShortestPath(0, weightedGraph, gIters);
    cout << "Dijkstra Shortest Path to Node 3: " << dPath[3] << " (Iters: " << gIters << ")\n\n";


    // ARRAY ALGORITHM TESTING (N Scale)
    cout << "Algorithm Verification \n";
    vector<int> testSizes = {1000, 5000, 10000};

    for (int i = 0; i < (int)testSizes.size(); i++) {
        int n = testSizes[i];
        cout << "\n";
        cout << "Testing Size N = " << n << "\n";
        cout << "\n";

        vector<int> data = generateRandomArray(n);

        // TIER 1: O(N log N) Sorting (Master's Theorem Evidence) 
        long long mIters = 0, qIters = 0;
        vector<int> mData = data, qData = data;

        auto sM = chrono::high_resolution_clock::now();
        mergeSort(mData, mIters);
        auto eM = chrono::high_resolution_clock::now();
        
        auto sQ = chrono::high_resolution_clock::now();
        quickSort(qData, qIters);
        auto eQ = chrono::high_resolution_clock::now();

        cout << "Merge Sort | " << chrono::duration<double, milli>(eM-sM).count() << "ms | Iters: " << mIters << "\n";
        cout << "Quick Sort | " << chrono::duration<double, milli>(eQ-sQ).count() << "ms | Iters: " << qIters << "\n";

        // TIER 2: O(N^2) Sorting (The Slower Sorting Algorithms) 
        long long bIters = 0, sIters = 0;
        vector<int> bData = data, sData = data;

        auto sB = chrono::high_resolution_clock::now();
        bubbleSortIterative(bData, bIters);
        auto eB = chrono::high_resolution_clock::now();

        auto sS = chrono::high_resolution_clock::now();
        selectionSort(sData, sIters);
        auto eS = chrono::high_resolution_clock::now();

        cout << "Bubble Sort| " << chrono::duration<double, milli>(eB-sB).count() << "ms | Iters: " << bIters << "\n";
        cout << "Selection  | " << chrono::duration<double, milli>(eS-sS).count() << "ms | Iters: " << sIters << "\n";

        //  TIER 3: O(N) & O(log N) Searching 
        long long kIters = 0, lIters = 0, biIters = 0;
        int target = data[n/2];

        kadaneMaxSubArray(data, kIters);
        linearSearch(data, target, lIters);
        
        sort(mData.begin(), mData.end()); // Prep for Binary Search
        binarySearchIterative(mData, target, biIters);

        cout << "Kadane (N) | Iters: " << kIters << "\n";
        cout << "Linear (N) | Iters: " << lIters << "\n";
        cout << "Binary(logN)| Iters: " << biIters << "\n\n";
    }

    return 0;
}