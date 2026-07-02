class Solution {
public:
    int rob(vector<int>& nums) {
        
        // ok so DP twice

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }

        std::vector<int> dp1(nums.size(), 1);
        std::vector<int> dp2(nums.size(), 1);

        dp1[0] = nums[0];
        dp1[1] = std::max(nums[0], nums[1]);
 
        dp2[nums.size() - 1] = nums[nums.size() - 1];
        dp2[nums.size() - 2] = std::max(nums[nums.size() - 2], nums[nums.size() - 1]);

        for (int i = 2; i < nums.size()-1; ++i) {
            dp1[i] = std::max(dp1[i-1], dp1[i-2] + nums[i]);
        }

        for (int i = nums.size() - 3; i > 0; --i) {
            dp2[i] = std::max(dp2[i+1], dp2[i+2] + nums[i]);
        }
        
        return std::max(dp1[nums.size()-2], dp2[1]);
        
    }
};
