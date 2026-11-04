class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int l = 0;
        int r = 0;

        int profit = 0;

        while (r < prices.size()){

            profit = std::max(profit, prices[r] - prices[l]);

            r ++;
            if (r < prices.size() && prices[r] < prices[l]){
                l = r;
            }

        }

        return profit;

    }
};
