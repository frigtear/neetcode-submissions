class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        result = list()
        subset = list()
        def helper(i):

            if i >= len(nums):
                result.append(subset.copy())
                return

            subset.append(nums[i])
            helper(i+1)

            while i < len(nums) - 1 and nums[i] == nums[i+1]:
                i += 1

            subset.pop()
            helper(i+1)

        helper(0)
        return result

            