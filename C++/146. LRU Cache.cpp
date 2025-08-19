#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int _capacity;
    list<pair<int, int>> dll;  // front = most recent, back = least recent
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    // constructor
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1; // not found
        }
        // Move this node to front (most recently used)
        dll.splice(dll.begin(), dll, it->second);
        return it->second->second; // return value
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Key exists → update value and move to front
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
            return;
        }

        // If capacity is full, evict least recently used
        if ((int)dll.size() == _capacity) {
            auto lru = dll.back();           // last element (least used)
            cache.erase(lru.first);          // remove from map
            dll.pop_back();                  // remove from list
        }

        // Insert new key-value at front
        dll.emplace_front(key, value);
        cache[key] = dll.begin();
    }
};
