class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = dp[i-coins[0]] + 1 + dp[coins[1]]  

        std::vector<int> dp(amount+1, -1);
        dp[0] = 0;
        int coin;
        int min_path = INT_MAX;

        for (int i = 0; i <= amount; i++){
            min_path = INT_MAX;        
            for (int c = 0; c < coins.size(); c++) {
                coin = coins[c];
                
                if (i - coin >= 0 && dp[i-coin] != -1) {

                    min_path = std::min(min_path, dp[i-coin] + 1);
                }

            }
            
            if (min_path != INT_MAX){
                dp[i] = min_path;
            }

            std::cout << i << " " << dp[i] << "    ";
        }

        return dp[amount];
    }
};
