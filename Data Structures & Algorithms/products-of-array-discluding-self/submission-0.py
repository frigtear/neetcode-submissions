class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:

        result = [1 for num in nums]
        fix = 1

        for i in range(1, len(nums)):
            fix *= nums[i - 1] 
            result[i] = fix 

        fix = 1
        for i in range(len(nums) - 2, -1, -1):
            fix *= nums[i + 1]
            result[i] *= fix

        return result
        


        

        