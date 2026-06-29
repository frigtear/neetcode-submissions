class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // dp[i] -> min cost to get to i step
        // min cost for i is the minimum of paying the cost n-1 and paying the cost n-2

        // so basically min(n[i-1] + n[i-1]) + min(n[i-2] + n[i-2])

        // dp[0] = 0
        // dp[1] = cost[0]

        std::vector dp(cost.size() + 1, 1);
        dp[0] = 0;
        dp[1] = 0;

        for ( size_t i = 2; i < cost.size() + 1; ++i ) {
            dp[i] = std::min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }



        return dp[cost.size()]; // this is ok because cost is for sure at least 2 long

    }
};
