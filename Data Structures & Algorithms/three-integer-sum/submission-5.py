class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:

        nums = sorted(nums)
        print(nums)
        result = list()
        for i in range(len(nums) - 1):
            l = i + 1
            r = len(nums) - 1

            if i > 0 and nums[i] == nums[i-1]:
                continue

            while l < r:

                triplet = nums[i] + nums[l] + nums[r]

                if triplet > 0:
                    r -= 1
                elif triplet < 0:
                    l += 1
                else:
                    result.append([nums[i],nums[l],nums[r]])
                    l += 1
                    while nums[l] == nums[l-1] and l < r:
                        l += 1
        return result


    # nums=[-1,0,1,2,-1,-4]
    # nums=[-4,-1,-1,0,1,2]

        



            
        