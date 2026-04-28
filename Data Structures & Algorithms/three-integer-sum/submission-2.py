class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums = sorted(nums)
        n = len(nums)

        for l in range(n - 2):
         
            if l > 0 and nums[l] == nums[l - 1]:
                continue
            
            c, r = l + 1, n - 1
            
            while c < r:
                s = nums[l] + nums[c] + nums[r]
                
                if s == 0:
                    res.append([nums[l], nums[c], nums[r]])
                    c += 1
                    r -= 1
                  
                    while c < r and nums[c] == nums[c - 1]:
                        c += 1
                   
                    while c < r and nums[r] == nums[r + 1]:
                        r -= 1
                elif s < 0:
                    c += 1
                else:
                    r -= 1
        
        return res
