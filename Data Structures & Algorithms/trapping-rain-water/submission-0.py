class Solution:
    def trap(self, height: List[int]) -> int:
        l, r, water = 0, len(height) - 1, 0
        maxl, maxr = float('-inf'), float('-inf')
        while l < r:
            maxl = max(height[l], maxl)
            maxr = max(height[r], maxr)
            if maxl > maxr:
                water += maxr - height[r]
                r -= 1
            else:
                water += (maxl - height[l])
                l += 1
        return water




