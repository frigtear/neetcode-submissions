class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // Basically at dp[i] simply just have the largest subseq up 2 that point
        // Then for a new one just go thru dp and if the number there is smaller than your current one
        // Take its subproblem and simply add 1!
        std::vector<int> dp(nums.size(), 1);
        dp[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
           // std::cout << nums[i];
            int maxval = 0;
            for (int j = i - 1; j > -1; j--){
                if (nums[j] < nums[i]){
                    maxval = std::max(maxval, dp[j]);
                }
            }
            dp[i] = maxval + 1;
        } 
        
/*
        for (size_t i = 0; i < dp.size(); ++i) {
            std::cout << "dp[" << i << "] = "
                      << dp[i] << '\n';
        }
        */
        int maxval = -1;
        for (int i = 0; i<dp.size(); i++){
            maxval = std::max(maxval, dp[i]);
        }
        
        return maxval;
    }
};
