class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        
        result = list()
        def helper(path, curr, length):

            if curr >= length:
                return path
            
            one = [helper(path + [nums[curr]], curr + 1, length)]
            two = [helper(path, curr + 1, length)]
            
            if all([val is not None for val in one]) and all([val is not None for val in two]):
                result.extend(one + two)

        helper(list(), 0, len(nums))

        return result


