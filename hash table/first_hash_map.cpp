#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map to store string keys and integer values
    std::unordered_map<std::string, int> hashTable;

    // Insert key-value pairs into the hash table
    hashTable["apple"] = 1;
    hashTable["banana"] = 2;
    hashTable["orange"] = 3;

    // Access and print values using their keys
    std::cout << "apple: " << hashTable["apple"] << std::endl;
    std::cout << "banana: " << hashTable["banana"] << std::endl;
    std::cout << "orange: " << hashTable["orange"] << std::endl;

    // Check if a key exists in the hash table
    std::string key = "banana";
    if (hashTable.find(key) != hashTable.end()) {
        std::cout << key << " found in the hash table." << std::endl;
    } else {
        std::cout << key << " not found in the hash table." << std::endl;
    }

    return 0;
}