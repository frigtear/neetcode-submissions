class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        #  "  "
        #   ^
        #   ^
        # {w, k}
        if not s:
            return 0
        chars = set()
        maxlen = 0
        l, r = 0, 0
        while r < (len(s)):
           
            if s[r] in chars:
                while s[l] != s[r]:
                    print(chars)
                    chars.remove(s[l])
                    l += 1
                l += 1

            chars.add(s[r])
            maxlen = max(maxlen, len(chars))
            r += 1
        return maxlen