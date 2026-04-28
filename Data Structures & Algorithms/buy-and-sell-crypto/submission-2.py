class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l, r = 0, 0
        maxprofit = 0
        while r < len(prices):
            profit = prices[r] - prices[l]
            if profit >= 0:
                maxprofit = max(maxprofit, profit)
                r += 1
            else:
                l += 1
        return maxprofit
