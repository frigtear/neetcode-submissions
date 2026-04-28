class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        

        if len(s2) < len(s1):
            return False

        s1_map = dict()
        s2_map = dict()

        for i in range(len(s1)):

            if s2[i] in s2_map:
                s2_map[s2[i]] += 1
            else:
                s2_map[s2[i]] = 1

            if s1[i] in s1_map:
                s1_map[s1[i]] += 1
            else:
                s1_map[s1[i]] = 1
        # s2="lecaabee"
        if s1_map == s2_map:
            return True
            
        for r in range(len(s1), len(s2)):
            print(s1_map, s2_map)
            l = r - len(s1)
            if s2[r] in s2_map:
                s2_map[s2[r]] += 1
            else:
                s2_map[s2[r]] = 1
            
            s2_map[s2[l]] -= 1
            if s2_map[s2[l]] == 0:
                del s2_map[s2[l]]
            
            
            l += 1
         
            if s1_map.items() == s2_map.items():
                return True

        return False





            