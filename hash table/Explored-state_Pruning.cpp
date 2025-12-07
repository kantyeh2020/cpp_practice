#include <unordered_set>
#include <queue>
#include <string>
#include <iostream>

int bfs_min_steps(const std::string& start, const std::string& target) {
    std::queue<std::pair<std::string, int>> q;
    std::unordered_set<std::string> visited;

    q.push({start, 0});
    visited.insert(start);

    while (!q.empty()) {
        auto [cur, dist] = q.front();
        q.pop();

        if (cur == target) return dist;

        // Example transitions: swap adjacent chars
        for (size_t i = 0; i + 1 < cur.size(); ++i) {
            std::string next = cur;
            std::swap(next[i], next[i+1]);
            if (!visited.count(next)) {
                visited.insert(next);
                q.push({next, dist + 1});
            }
        }
    }
    return -1; // unreachable
}

int main() {
    std::cout << bfs_min_steps("abcd", "badc") << "\n";
}
