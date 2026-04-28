class Solution:

    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        letters_s, letters_t = dict(), dict()
    
        for i in range(len(s)):
            s_letter, t_letter = s[i], t[i]
            
            if s_letter not in letters_s:
                letters_s[s_letter] = 1
            else:
                letters_s[s_letter] += 1

            if t_letter not in letters_t:
                letters_t[t_letter] = 1
            else:
                letters_t[t_letter] += 1

        print(letters_s, letters_t)
        return letters_s == letters_t



            