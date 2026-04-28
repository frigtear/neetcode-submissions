class Solution:
    def isPalindrome(self, s: str) -> bool:
        #  "Was it a car or a cat I saw?"
        #   ^                           ^
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1
           # print(s[l], s[r])
            if s[l].lower() != s[r].lower():
                return False
            else:
                l += 1
                r -= 1
        return True
