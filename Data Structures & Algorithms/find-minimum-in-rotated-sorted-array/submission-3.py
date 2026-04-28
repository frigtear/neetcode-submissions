class Solution:
    def findMin(self, nums: List[int]) -> int:
        #  nums = [3,4,5,6,1,2]
        # rightmost smaller - throw out left
        # leftmost smaller = throw out right
        # both smaller = return number

        l, r = 0, len(nums) - 1
        smallest = float("inf")
        while l <= r:
            print(nums[l],nums[r])
            c = ((l + r) // 2)
            smallest = min(smallest, nums[c])
            if nums[c] > nums[r]:
                l = c + 1
            else:
                r = c - 1
        return min(smallest,nums[c])
