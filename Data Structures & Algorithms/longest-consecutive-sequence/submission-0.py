class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # nums=[2,20,4,10,3,4,5]
        # 
        nums = set(nums)
        maxcount = 0
        for num in nums:
            count = 0
            if not num-1 in nums:
                while num in nums:  
                    count += 1
                    maxcount = max(maxcount, count)
                    num = num + 1
        return maxcount


