#include <unordered_map>
#include <string>
#include <iostream>

struct LogEntry {
    std::string ip;
    std::string path;
    int status;

    bool operator==(const LogEntry& other) const {
        return ip == other.ip && path == other.path && status == other.status;
    }
};

struct LogEntryHash {
    std::size_t operator()(const LogEntry& e) const {
        std::size_t h1 = std::hash<std::string>()(e.ip);
        std::size_t h2 = std::hash<std::string>()(e.path);
        std::size_t h3 = std::hash<int>()(e.status);
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

int main() {
    std::unordered_map<LogEntry, int, LogEntryHash> freq;

    // Fake data
    LogEntry a{"192.168.0.1", "/index.html", 200};
    LogEntry b{"192.168.0.2", "/login", 200};
    LogEntry c{"192.168.0.1", "/index.html", 200};

    freq[a]++;
    freq[b]++;
    freq[c]++;

    for (const auto& p : freq) {
        std::cout << p.first.ip << " " << p.first.path
                  << " " << p.first.status << " => " << p.second << "\n";
    }
}
