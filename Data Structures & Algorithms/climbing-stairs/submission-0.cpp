class Solution {
public:
    int climbStairs(int n) {


        // dp[n] -> number of ways to climb to the nth step of the staricase
        // dp[1] -> 1 way
        // dp[2] -> 2 ways
        // dp[3] -> 2 ways to get to stair before it + 
        // at dp[n] what new ways get here are added? 
        // Number of ways to get to dp[n-1] + number of ways to get to dp[n-2]
        
        if (n <= 2){
            return n;
        }

        std::vector<int> dp(n, 1); 

        dp[0] = 1;
        dp[1] = 2;
        
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n-1];
        
    }
};
