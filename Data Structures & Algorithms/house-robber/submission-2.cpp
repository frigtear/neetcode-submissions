class Solution {
public:
    int rob(vector<int>& nums) {
        // dp[i] the max amount of money from house i
        // dp[i] = max()
        // If taking this one lowers the amount of money we taking dont take it
        // dp[i] = max(dp[i-1], dp[i-1] - nums[i-1] + nums[i-2] + nums[i])

        // [1, 1, 3, 3] -> 
        // [1, 1, 1, 1]
        // [1, 1, ]
        // max(1, 4, )
        // max(4, 4) -> 4


        // [2, 9, 8, 3, 6]
        // [2, 9, , ]

        //  max(dp[i-1], dp[i-2] + nums[i]);

        std::vector<int> dp(nums.size(), 0);

        if (nums.size() == 1){
            return nums[0];
        }
        else if (nums.size() == 2){
            return std::max(nums[0], nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (size_t i = 2; i < nums.size(); ++i){
            dp[i] = std::max(dp[i-1], dp[i-2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};
