class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        result = list()
        combination = list()

        def helper(num, i):
            
            print(num, i)

            if num == 0:
                result.append(combination.copy())
                return
            elif i >= len(nums) or num < 0:
                return

            combination.append(nums[i])
            helper(num - nums[i], i)
            combination.pop()
            helper(num, i+1)

        helper(target, 0)
        return result