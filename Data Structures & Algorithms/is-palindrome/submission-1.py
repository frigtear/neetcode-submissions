class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = [let.lower() for let in s if let.isalnum()]
        print(s)
        return s[::-1] == s