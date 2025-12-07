#include <unordered_map>
#include <tuple>
#include <iostream>

struct State {
    int n, k;
    bool operator==(const State& other) const {
        return n == other.n && k == other.k;
    }
};

struct StateHash {
    std::size_t operator()(const State& s) const {
        // Simple hash combine
        return std::hash<int>()(s.n) ^ (std::hash<int>()(s.k) << 1);
    }
};

std::unordered_map<State, long long, StateHash> memo;

long long ways(int n, int k) {
    if (n == 0) return 1;
    if (n < 0 || k == 0) return 0;

    State st{n, k};
    auto it = memo.find(st);
    if (it != memo.end()) return it->second;

    // Either use k at least once, or don't use k
    long long res = ways(n - k, k) + ways(n, k - 1);

    memo[st] = res;
    return res;
}

int main() {
    std::cout << ways(10, 10) << "\n";
}
