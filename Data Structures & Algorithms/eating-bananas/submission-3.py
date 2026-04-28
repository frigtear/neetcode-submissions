class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        l, r = 1, max(piles)
        rate = l
        while l <= r:
            k = (l + r) // 2
            hours = 0
            for pile in piles:
                hours += math.ceil(float(pile) / k)

            print(k, hours)

            if hours <= h:
                rate = k
                r = k - 1
            else:
                l = k + 1
        
        return rate

            
            






                


                    
