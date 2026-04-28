class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        l, r = 0, 0
        chars = set()
        longest_substring_length = 0

        while r < len(s):

            if s[r] in chars:
                while s[r] in chars:
                    chars.remove(s[l])
                    l += 1
                    
            chars.add(s[r])
            longest_substring_length = max(longest_substring_length, r - l+1)
            r += 1

            

        return longest_substring_length

            

