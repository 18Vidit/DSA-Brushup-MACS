#ifndef CUSTOM_STRUCTURES_HPP
#define CUSTOM_STRUCTURES_HPP

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 1. CIRCULAR LINKED LIST
struct CNode {
    int data;
    CNode* next;
    CNode(int val) : data(val), next(nullptr) {}
};

inline void demoCircularLinkedList() {
    cout << "\n Circular Linked List Operations \n";
    
    // Create & Insert 
    CNode* head = new CNode(10);
    CNode* second = new CNode(20);
    CNode* third = new CNode(30);
    head->next = second;
    second->next = third;
    third->next = head; 
    // Update 
    head->data = 15; 
    // Traverse
    cout << "Traverse: ";
    CNode* temp = head;
    if (head != nullptr) {
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    cout << "\n";
    // Search
    cout << "Search for 20: ";
    temp = head;
    bool found = false;
    do {
        if (temp->data == 20) { found = true; break; }
        temp = temp->next;
    } while (temp != head);
    cout << (found ? "Found!\n" : "Not found.\n");
    // Delete 
    delete third; delete second; delete head;
}

// 2. BINARY SEARCH TREE (BST){Time complexity: O(log n) on average}[doing this first time]
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
// Insert into BST
inline TreeNode* insertBST(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (val < root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}
// Inorder Traversal (Left, Root, Right) - Prints in sorted order
inline void inorderTraverse(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraverse(root->left);
    cout << root->data << " ";
    inorderTraverse(root->right);
}
// Search in BST
inline bool searchBST(TreeNode* root, int target) {
    if (root == nullptr) return false;
    if (root->data == target) return true;
    if (target < root->data) return searchBST(root->left, target);
    return searchBST(root->right, target);
}
inline void demoTree() {
    cout << "\n Tree (Binary Search Tree) Operations \n";
    // Create & Insert
    TreeNode* root = nullptr;
    root = insertBST(root, 50);
    insertBST(root, 30);
    insertBST(root, 70);
    insertBST(root, 20);
    insertBST(root, 40);
    // Traverse
    cout << "Traverse (Inorder): ";
    inorderTraverse(root);
    cout << "\n";
    // Search
    cout << "Search for 40: " << (searchBST(root, 40) ? "Found!\n" : "Not found.\n");
}
// Update: In a BST, updating requires deleting the old value and inserting the new one to maintain structure.


// 3. GRAPH [doing for the first time]
inline void demoGraph() {
    cout << "\n Graph (Adjacency List) Operations \n";
    // Create: Map where Key is the Node, Value is a list of connected Nodes
    unordered_map<int, vector<int>> adjList;
    // Insert (Adding undirected edges)
    auto addEdge = [&](int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);// For undirected graph, add both ways
    };    
    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    // Traverse 
    cout << "Traverse (Connections):\n";
    for (auto const& pair : adjList) {
        cout << "  Node " << pair.first << " is connected to: ";
        for (int neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << "\n";
    }
    // Search 
    cout << "Search (Is 0 connected to 4?): ";
    auto it = find(adjList[0].begin(), adjList[0].end(), 4);
    cout << (it != adjList[0].end() ? "Yes!\n" : "No.\n");
    // Delete (Remove edge between 0 and 4)
    adjList[0].erase(remove(adjList[0].begin(), adjList[0].end(), 4), adjList[0].end());
    adjList[4].erase(remove(adjList[4].begin(), adjList[4].end(), 0), adjList[4].end());
    cout << "After deleting edge 0-4, Node 0 connections: " << adjList[0].size() << "\n";
}

// CALL FUNCTION
inline void runAllCustomDemos() {
    demoCircularLinkedList();
    demoTree();
    demoGraph();
}

#endif