#ifndef MAPS_HPP
#define MAPS_HPP

#include <iostream>
#include <unordered_map> // C++ Hash Map (O(1) average time)
#include <map>           // C++ Tree Map / Red-Black Tree (O(log N) time)
#include <string>

using namespace std;


// 1. UNORDERED MAP (Hash Map)

inline void demoHashMap() {
    cout << "\n Unordered Map (Hash Map) Operations \n";
    cout << "Notice: The output order will seem random because it uses hashing.\n";    
    // Create
    unordered_map<string, int> scores;
    // Insert / Update
    scores["Vidit"] = 95;
    scores["Aman"] = 88;
    scores["Zack"] = 92;
    scores["Vidit"] = 99; // This updates the existing key
    // Traverse 
    cout << "Traverse:\n";
    for (auto const& pair : scores) {
        cout << "  Key: " << pair.first << ", Value: " << pair.second << "\n";
    }
    // Search
    cout << "Search for 'Vidit': ";
    if (scores.find("Vidit") != scores.end()) {
        cout << "Found! Score is " << scores["Vidit"] << "\n";
    } else {
        cout << "Not found.\n";
    }
    // Delete
    scores.erase("Aman");
    cout << "After erasing 'Aman', size is now: " << scores.size() << "\n";
}
// 2. MAP (Tree Map / Red-Black Tree)
inline void demoTreeMap() {
    cout << "\n Map (Tree Map) Operations \n";
    cout << "Notice: The output will be automatically sorted alphabetically by Key.\n";
    
    // Create
    map<string, int> rankings;
    
    // Insert
    rankings["Charlie"] = 3;
    rankings["Alice"] = 1;
    rankings["Bob"] = 2;
    // Update
    rankings["Alice"] = 10; // Changes Alice's rank from 1 to 10
    // Traverse 
    cout << "Traverse:\n";
    for (auto const& pair : rankings) {
        cout << "  Key: " << pair.first << ", Value: " << pair.second << "\n";
    }
    // Search
    cout << "Search for 'Bob': ";
    if (rankings.find("Bob") != rankings.end()) {
        cout << "Found! Rank is " << rankings["Bob"] << "\n";
    }
    // Delete
    rankings.erase("Charlie");
    cout << "After erasing 'Charlie', size is now: " << rankings.size() << "\n";
}


// CALL FUNCTION

inline void runAllMapDemos() {
    demoHashMap();
    demoTreeMap();
}

#endif