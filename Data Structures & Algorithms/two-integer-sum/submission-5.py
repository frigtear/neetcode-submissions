class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        vals = dict()

        for i in range(len(nums)):
            if target - nums[i] in vals:
                return [vals[target - nums[i]], i]
            vals[nums[i]] = i

        return 
        