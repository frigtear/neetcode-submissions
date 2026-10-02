#include <unordered_map>
#include <list>
#include <utility> // for std::pair

class LRUCache {

private:
    int m_capacity;
    // 1. FIXED: Changed list type from <int> to <std::pair<int, int>>
    std::list<std::pair<int, int>> values; 
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hashmap; 

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (!hashmap.contains(key)){
            return -1;
        }

        values.splice(values.begin(), values, hashmap[key]);
        return hashmap[key]->second;
    }
    
    void put(int key, int value) {
        if (hashmap.contains(key)){
            hashmap[key]->second = value;
            values.splice(values.begin(), values, hashmap[key]);
            return;
        }

        if (values.size() == m_capacity){
            hashmap.erase(values.back().first); 
            values.pop_back();
        }

        values.push_front({key, value}); 
        hashmap[key] = values.begin();
    }
};
