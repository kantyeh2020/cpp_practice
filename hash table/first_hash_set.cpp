#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    std::unordered_set<std::string> s;

    s.insert("cat");
    s.insert("dog");
    s.insert("cat"); // Duplicate, will not be added

    if (s.count("cat")) {       // or s.find("cat") != s.end()
        std::cout << "cat exists\n";
    }

    s.erase("dog");

    for (const auto &x : s) {
        std::cout << x << "\n";
    }

    return 0;
}