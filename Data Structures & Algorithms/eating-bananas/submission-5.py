class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # k = 3
        #  [1,4,3,2]

        def eat_banana(rate, piles):
            hours_needed = 0
            for stack in piles:
                hours_needed += math.ceil(stack / rate)
            return hours_needed
                

        l,r = 1, max(piles)
        while l < r:
            c = (l + r) // 2
            hours_needed = eat_banana(c,piles)

            if hours_needed <= h:
                r = c
            else:
                l = c + 1

        return l
