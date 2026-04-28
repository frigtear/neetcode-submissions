class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        
        result = list()
        combination = list()

        candidates = sorted(candidates)


        # candidates=[9,2,2,4,6,1,5]
        # [1, 2, 2, 4, 5, 6, 6]

        def helper(num, i):

            if num == 0:
                result.append(combination.copy())
                return
                
            elif num < 0 or i >= len(candidates):
                return

          

            combination.append(candidates[i])
            helper(num - candidates[i], i+1)
            while i < len(candidates) - 1 and candidates[i] == candidates[i+1]:
                i += 1
            combination.pop()
            helper(num, i+1)

        helper(target, 0)
        return result
            

