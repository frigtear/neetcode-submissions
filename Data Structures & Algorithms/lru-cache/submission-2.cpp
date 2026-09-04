class LRUCache {

private:
       std::map<int, int> use_times;
        priority_queue<pair<int, int>,
               vector<pair<int, int>>,
               greater<pair<int, int>>> heap;
        std::map<int, int> values;
        int m_capacity = 0;
        int time = 0;

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        if (!values.contains(key)){
            return -1;
        }
        use_times[key] = time;
        heap.push({time, key});
        time++;
        return values[key];
    
    }
    
    void put(int key, int value) {
        if (values.size() < m_capacity || values.contains(key)) {
            values[key] = value;
        }
        else {
          // Now get the least recently used by popping from heap
          while (heap.top().first != use_times[heap.top().second]){
            heap.pop();
          }
          auto [lru_time, lru_key] = heap.top();
          heap.pop();

          values.erase(lru_key);
          values[key] = value;
        }
      
        use_times[key] = time;
        heap.push({time, key});
        time++;


    }
};
