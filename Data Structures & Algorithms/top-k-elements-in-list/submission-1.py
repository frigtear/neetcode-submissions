class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
      

        groups = dict()
        for num in nums:
            if num in groups:
                groups[num] += 1
            else:
                groups[num] = 1

        nums = list(set(nums))

        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if groups[nums[j]] > groups[nums[i]]:
                    temp = nums[i]
                    nums[i] = nums[j]
                    nums[j] = temp
        
        print(groups)
        print(nums)
        return nums[:k]