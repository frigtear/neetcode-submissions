class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums_s = set(nums)
        count = 1
        maxcount = 1
        while nums_s:
            value = nums_s.pop()
         #   print(value)
            if value - 1 not in nums_s:
                while value + 1 in nums_s:
                    count += 1
                    maxcount = max(maxcount, count)
                    nums_s.remove(value + 1)
                    value += 1
            else:
                nums_s.add(value)
            
            count = 1

        if nums:
            return maxcount
        else:
            return 0


                
       

            
          


        