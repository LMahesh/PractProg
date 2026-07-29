
//timecomplexity for read o(n) and add o(1)

#include <iostream>
#include <vector>
#include <algorithm>

class MRUCache {
private:
    std::vector<int> cache;
    size_t capacity;

    void printCache() const {
        for (size_t i = 0; i < cache.size(); ++i) {
            std::cout << cache[i] << (i == cache.size() - 1 ? "" : ",");
        }
        std::cout << "\n";
    }

public:
    MRUCache(size_t cap) : capacity(cap) {}

    // Initialize the cache with starting values
    void initialize(const std::vector<int>& initialValues) {
        cache = initialValues;
        std::cout << "Initial cache: ";
        printCache();
    }

    // Read an element: Moves it to the back (Most Recently Used position)
    void readElement(int val) {

        auto it = std::find(cache.begin(), cache.end(), val);
        if (it != cache.end()) {
            cache.erase(it);  // Remove from current position
            cache.push_back(val); // Move to the back
        }
        std::cout << "After read " << val << " o/p: ";
        printCache();
    }

    // Add an element: If full, replaces the MRU element (the back element)
    void addElement(int val) {
        if (cache.size() >= capacity) {
            cache.pop_back(); // Evict the most recently used element
        }
        cache.push_back(val);
        std::cout << "And add " << val << " o/p: ";
        printCache();
    }
};

int main() {
    // Cache capacity is 5
    MRUCache myCache(5);

    // 1. Input initial values
    myCache.initialize({ 2, 3, 4, 5, 6 });

    // 2. Read element 4
    myCache.readElement(4);

    // 3. Add element 7
    myCache.addElement(7);

    return 0;
}
