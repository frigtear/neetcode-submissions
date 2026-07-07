class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        std::vector<int> mins(nums.size(), 0);
        std::vector<int> maxs(nums.size(), 0);

        maxs[0] = nums[0];
        mins[0] = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            int num = nums[i];
    
            maxs[i] = std::max({num, maxs[i-1] * num, mins[i-1] * num});
            mins[i] = std::min({num, mins[i-1] * num, maxs[i-1] * num});
    
        }

        int result = INT_MIN;
        for (auto num : maxs){  
            std::cout << num << " ";
            result = std::max(result, num);
        }

        return result;


    }
};
