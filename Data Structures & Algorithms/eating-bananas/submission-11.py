class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        
        def num_hours(rate):
            time = 0
            
            for pile in piles:
                time += math.ceil(pile / rate)
            
            return time <= h

       

        l, r = 1, max(piles)
        while l <= r:
            c = (l + r) // 2
            
            if not num_hours(c):
                l = c + 1
            else:
                r = c - 1

        return l



                


                    
