#ifndef LINEAR_STRUCTURES_HPP
#define LINEAR_STRUCTURES_HPP

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <list>          // Doubly Linked List
#include <forward_list>  // Singly Linked List
#include <algorithm>    

using namespace std;

// 1. STANDARD ARRAY (Static Size)
inline void demoArray() {
    cout << "\n Array (Static) Operations \n";
    
    // Create 
    array<int, 3> arr = {10, 20, 30}; 
    // Update
    arr[1] = 99; 
    // Traverse
    cout << "Traverse: ";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    // Search (Using standard algorithm)
    cout << "Search for 99: ";
    auto it = find(arr.begin(), arr.end(), 99);
    if (it != arr.end()) cout << "Found!\n";
    else cout << "Not found.\n";
    // Delete: You CANNOT delete elements from a static array to change its size!
    cout << "Delete: Cannot dynamically delete from std::array.\n";
}

// 2. VECTOR (Dynamic Array)
inline void demoVector() {
    cout << "\n Vector (Dynamic Array) Operations \n";
    // Create
    vector<int> vec; 
    // Insert
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);
    // Traverse
    cout << "Traverse: ";
    for (int i = 0; i < (int)vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << "\n";
    // Update
    vec[0] = 500; 
    cout << "Update index 0 to: " << vec[0] << "\n";
    // Search
    cout << "Search for 200: " << (find(vec.begin(), vec.end(), 200) != vec.end() ? "Found!\n" : "Not found.\n");
    // Delete (Remove the last element, which is 300)
    vec.pop_back(); 
    cout << "After pop_back (Delete), size is now: " << vec.size() << "\n";
}

// 3. STRING
inline void demoString() {
    cout << "\n String Operations \n";
    // Create
    string name = "Vidit"; 
    // Insert / Update
    name += " Arora"; // Appends to the end
    // Traverse
    cout << "Traverse (Char by Char): ";
    for (int i = 0; i < (int)name.length(); i++) {
        cout << name[i] << "-";
    }
    cout << "\n";
    // Search
    cout << "Search for 'Arora': ";
    if (name.find("Arora") != string::npos) {
        cout << "Found at index " << name.find("Arora") << "\n";
    }
    // Delete (Erase 5 characters starting from index 6)
    name.erase(6, 5); 
    cout << "After Delete: " << name << "\n";
}
// 4. DOUBLY LINKED LISTS
inline void demoDoublyLinkedList() {
    cout << "\n Doubly Linked List Operations \n";
    // Create (std::list is a doubly-linked list in C++)
    list<int> dll;
    // Insert (Can push to front or back efficiently)
    dll.push_back(10);
    dll.push_back(20);
    dll.push_front(5); 
    // Traverse 
    cout << "Traverse: ";
    for (int value : dll) {
        cout << value << " ";
    }
    cout << "\n";
    // Update (Change the front element)
    dll.front() = 99; 
    cout << "Update: Front is now " << dll.front() << "\n";
    // Search
    cout << "Search for 10: " << (find(dll.begin(), dll.end(), 10) != dll.end() ? "Found!\n" : "Not found.\n");
    // Delete 
    dll.remove(20);
    cout << "After removing 20, front is: " << dll.front() << "\n";
}

// 5. SINGLY LINKED LIST
inline void demoSinglyLinkedList() {
    cout << "\n Singly Linked List Operations \n";
    // Create (std::forward_list is a singly-linked list in C++)
    forward_list<int> sll;
    // Insert (Singly linked lists only efficiently push to the front)
    sll.push_front(30);
    sll.push_front(20);
    sll.push_front(10); 
    // Traverse
    cout << "Traverse: ";
    for (int value : sll) {
        cout << value << " ";
    }
    cout << "\n";
    // Search 
    cout << "Search for 20: ";
    auto it = find(sll.begin(), sll.end(), 20);
    if (it != sll.end()) cout << "Found!\n";
    else cout << "Not found.\n";
    // Update
    sll.front() = 99;
    // Delete 
    sll.pop_front();
    cout << "After pop_front (Delete), head is now: " << sll.front() << "\n";
}

// CALL FUNCTION
inline void runAllLinearDemos() {
    demoArray();
    demoVector();
    demoString();
    demoDoublyLinkedList();
    demoSinglyLinkedList();
}

#endif