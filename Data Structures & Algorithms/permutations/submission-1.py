class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        result = list()

        def helper(path, used):

            for i in range(len(nums)):
                if i not in used:
                    helper(path + [nums[i]], used | {i}) 

            if len(path) == len(nums):
                result.append(path)

        helper(list(), set())

        return result
            