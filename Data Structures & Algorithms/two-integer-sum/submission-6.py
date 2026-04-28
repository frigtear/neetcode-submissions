class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # nums = [3,4,5,6], target = 7
        #           ^
        # map 4:0 -> return (1, 0)

        vals = dict()
        for i, num in enumerate(nums):
            diff = target - num
            if num in vals:
                return [vals[num], i]
            else:
                vals[diff] = i
