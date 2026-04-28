class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            while l < r and numbers[l] == numbers[l + 1]:
                l += 1
            while r > l and numbers[r] == numbers[r - 1]:
                r -= 1

            curr_sum = numbers[l] + numbers[r] 
            if curr_sum == target:
                return [l+1, r+1]
            elif curr_sum > target:
                r -= 1
            else:
                l += 1

        

            
            
            