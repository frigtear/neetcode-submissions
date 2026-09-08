class MinStack {

private:
    std::vector<int> m_vector;
    std::priority_queue<int, std::vector<int>, std::greater<int>> dq;
    std::unordered_map<int, int> freqMap;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        m_vector.push_back(val);
        dq.push(val);
        if (freqMap.contains(val)){
            freqMap[val] -= 1;
            if (freqMap[val] <= 0){
                freqMap.erase(val);
            }
        }
    }
    
    void pop() {
        if (!m_vector.empty()){
            int popped_value = m_vector.back();
            m_vector.pop_back();
            freqMap[popped_value] += 1;
        }
    }
    
    int top() {
        return m_vector.back();
    }
    
    int getMin() {
        
        while (!dq.empty() && freqMap.contains(dq.top())){
            freqMap[dq.top()] -= 1;
            if (freqMap[dq.top()] <= 0){
                freqMap.erase(dq.top());
            }
            dq.pop();
        }

        return dq.top();

    }
};
