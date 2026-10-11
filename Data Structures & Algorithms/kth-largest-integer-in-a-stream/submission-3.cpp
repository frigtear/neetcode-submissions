class KthLargest {

private:
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int m_k;

public:
    KthLargest(int k, vector<int>& nums) : m_k(k){
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        for (size_t i = 0; i < nums.size() && i < k; ++i){
            q.push(nums[i]);
        }
    }
    
    int add(int val) {

        if (q.size() < m_k){
            q.push(val);
        }
        else if (val > q.top()){
            q.pop();
            q.push(val);
        }
        
        return q.top();
        
    }
};
