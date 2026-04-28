class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # put input into a set
        # loop thru using while loop
        # if 1 less exists 

        nums = set(nums)
        longest_sequence = 0
        for num in nums.copy():
            sequence = 0
            while num - 1 not in nums and num in nums: 
                sequence += 1
                nums.remove(num)
                num += 1
            longest_sequence = max(longest_sequence, sequence)

        return longest_sequence