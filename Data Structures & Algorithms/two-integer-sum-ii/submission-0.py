class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        #  [1,2,3,4]
        #   ^ ^
        #
        #
        # cursum -> 3  target -> 3

        l, r = 0, len(numbers) - 1
        while l < r:
            s = numbers[l] + numbers[r]
           # print(numbers[l], numbers[r])
            if s > target:
                r -= 1
            elif s < target:
                l += 1
            else:
                return [l+1, r+1]