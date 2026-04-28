class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        result = list()
        permutation = list()

        def helper(i):
            if i >= len(nums):
                result.append(nums.copy())
                return

            for j in range(i, len(nums)):
                nums[i], nums[j] = nums[j], nums[i]
                helper(i+1)
                nums[i], nums[j] = nums[j], nums[i]

        helper(0)
        return result