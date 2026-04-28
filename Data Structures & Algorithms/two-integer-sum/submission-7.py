class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        vals = dict()
        for i in range(len(nums)):
            number = nums[i]
            if target - number in vals:
                return [vals[target - number], i]
            else:
                vals[number] = i
        
        return None
