class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # sum -> 
        # expected -> len(nums) 
        # [1,2,3,2,2]
        # 

        slow, fast = 0, 0

        while True:
            slow = nums[slow]
            fast = nums[fast]
            fast = nums[fast]
            if slow == fast:
                print(slow, nums)
                temp = 0
                while temp != slow:
                    temp = nums[temp]
                    slow = nums[slow]
                return slow

        