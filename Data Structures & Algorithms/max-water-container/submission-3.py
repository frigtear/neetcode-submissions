class Solution:
    def maxArea(self, heights: List[int]) -> int:
        
        r, l = 0, len(heights) - 1
        max_water = 0
        while r < l:
            distance = l - r
            water = min(heights[r], heights[l]) * distance
            max_water = max(max_water, water)

            if heights[r] <= heights[l]:
                r += 1
            else:
                l -= 1

        return max_water



