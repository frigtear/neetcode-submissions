class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        result = list()
        def helper(path, curr, length):

        
            if curr >= length:
                result.append(path)
                return

            helper(path + [nums[curr]], curr + 1, length)
            helper(path, curr + 1, length)


        helper(list(), 0, len(nums))

        return result


