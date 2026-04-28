class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # abaca
        # b, a, c
        # bbbbac
        
        if len(s2) < len(s1):
            return False

        window = dict()
        needed = {char:s1.count(char) for char in s1}
        l = 0
        for r in range(len(s2)):
            print(needed, window)
            print(l, r, s2[l], )
          
            if s2[r] in window:
                window[s2[r]] += 1
            else:
                window[s2[r]] = 1

            if r - l >= len(s1):
                window[s2[l]] -= 1
                if window[s2[l]] == 0:
                    del window[s2[l]]
                l += 1

            if needed == window:
                return True

        return False




            