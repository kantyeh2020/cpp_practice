#include <unordered_map>
#include <list>
#include <iostream>

template <typename Key, typename Value>
class LRUCache {
public:
    LRUCache(size_t capacity) : capacity_(capacity) {}

    bool get(const Key& key, Value& out) {
        auto it = map_.find(key);
        if (it == map_.end()) return false;

        // Move this key to front (most recently used)
        usage_.splice(usage_.begin(), usage_, it->second.second);
        out = it->second.first;
        return true;
    }

    void put(const Key& key, const Value& value) {
        auto it = map_.find(key);
        if (it != map_.end()) {
            // Update value & move to front
            it->second.first = value;
            usage_.splice(usage_.begin(), usage_, it->second.second);
            return;
        }

        // Insert new
        if (usage_.size() == capacity_) {
            // Evict least recently used (back of list)
            Key lru_key = usage_.back();
            usage_.pop_back();
            map_.erase(lru_key);
        }

        usage_.push_front(key);
        map_[key] = {value, usage_.begin()};
    }

private:
    size_t capacity_;
    std::list<Key> usage_; // most recent at front
    // key -> (value, iterator to list node)
    std::unordered_map<Key, std::pair<Value, typename std::list<Key>::iterator>> map_;
};

int main() {
    LRUCache<int, std::string> cache(2);
    cache.put(1, "one");
    cache.put(2, "two");

    std::string v;
    if (cache.get(1, v)) std::cout << v << "\n"; // "one" (1 is now most recent)

    cache.put(3, "three"); // evicts key 2

    if (!cache.get(2, v)) std::cout << "2 evicted\n";
    if (cache.get(3, v)) std::cout << v << "\n"; // "three"
}