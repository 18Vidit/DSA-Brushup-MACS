**DSA-Brushup-MACS**

A comprehensive C++ repository designed for brushing up on Abstract Data Structures and profiling core Algorithms. Built as a hands-on refresher for midterms and algorithmic problem-solving.

**Objective:**
To implement, test, and benchmark standard Data Structures (via C++ STL) alongside fundamental sorting, searching, and graph algorithms. This project includes a central benchmarking tool (`main.cpp`) to verify theoretical time complexities (such as Master's Theorem) by tracking real-world execution time and iteration counts across various input sizes.

**Repository Structure:**

```
DSA-Brushup-MACS/
├── main.cpp                  # The main runner, profiler, & tester
├── data_structures/          # STL & Custom CRUD operations
│   ├── LinearStructures.hpp  # Arrays, Vectors, Strings, Singly/Doubly Lists
│   ├── Maps.hpp              # Unordered Map (Hash), Map (Tree)
│   └── CustomStructures.hpp  # Trees, Graphs, Circular LL
└── algorithms/
    ├── sorting/
    │   ├── BubbleSort.hpp    # Standard iterative
    │   ├── RecursiveBubble.hpp
    │   ├── SelectionSort.hpp
    │   ├── InsertionSort.hpp # Standard iterative
    │   ├── RecursiveInsertion.hpp
    │   ├── MergeSort.hpp     # O(N log N)
    │   └── QuickSort.hpp     # O(N log N)
    ├── searching/
    │   ├── LinearSearch.hpp  # O(N) baseline
    │   ├── BinarySearch.hpp  # Iterative & Recursive versions
    │   ├── BFS.hpp           # Breadth-First Search
    │   └── DFS.hpp           # Depth-First Search
    └── extras/
        ├── Dijkstra.hpp      # Shortest path via Priority Queue/Min-Heap
        └── Kadane.hpp        # Maximum subarray sum in O(N)
```
     
**Performance Analysis:**

To empirically verify our theoretical time complexities, we benchmarked our algorithms by scaling the input array from N = 1,000 to N = 10,000 (a 10x increase). 

```
  ALGORITHM TIER :     GROWTH FACTOR            THEORETICAL BOUND VERIFIED 
Merge & Quick Sort    ~13.5x work         O(N log N)  -> Master's Theorem
Bubble & Selection    100.0x work         O(N²)       -> Polynomial Growth
Kadane & Linear       10.0x  work         O(N)        -> Linear Bound
Binary Search         +3 steps total      O(log N)    -> Logarithmic Halving
BFS, DFS, Dijkstra    Strictly V+E        O(V+E)      -> Graph Traversal
Note: A 10x increase in array size caused Bubble Sort to do 100x more work, 
perfectly demonstrating the fatal scaling of O(N²) compared to O(N log N).
```

**Explained in words:**

The Divide & Conquer ALgos: O(N log N)
Verified via the Master's Theorem
Merge Sort: Iterations grew from ~10k to ~133k (a 13.4x increase).
Quick Sort: Iterations grew from ~11k to ~164k (a 14.1x increase).
The Takeaway: Instead of a massive 100x penalty, the `log N` factor kept the scaling highly efficient. This perfectly aligns with the Master's Theorem (Case 2) predictions for divide-and-conquer recurrences.

The Quadratic Heavyweight ALgos: O(N²)
Verified via Polynomial Growth
Bubble & Selection Sort: Iterations skyrocketed from ~500,000 to nearly 50,000,000.
The Takeaway: A 10x increase in input size resulted in a massive 100x increase in actual work, proving the harsh reality of the N² theoretical bound.

The Linear & Logarithmic Algos: O(N) & O(log N)
Kadane's & Linear Search:** Iterations scaled perfectly by 10x, representing a direct 1:1 linear relationship with the data size.
Binary Search:** It took only 3 extra steps to search a dataset 10 times larger, showcasing the extreme efficiency of halving the search space.

Graph Traversals: O(V + E)
BFS & DFS: Traversed our 6-node, 7-edge network in exactly 6 steps.
Dijkstra's: Found the shortest path in 7 steps, verifying the efficiency of using a Min-Heap Priority Queue for edge relaxation.


*some of the algos and DS(s) , i have shown are the ones which i have studied for the first time (basically i haven't used these before this task and explored them today out of pure curiosity and further learning).*



**AUTHOR: Vidit Arora**

