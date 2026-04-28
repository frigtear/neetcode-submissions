class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        
        def most_frequent(characters : dict) -> int:
            result = 0
            for char in characters:
                result = max(result, characters[char])

            return result


        characters = dict()
        l = 0
        longest_window_length = 0

        for r in range(len(s)):
            window_length = (r - l) + 1
            if s[r] in characters:
                characters[s[r]] += 1
            else:
                characters[s[r]] = 1

            while window_length - most_frequent(characters) > k:
                characters[s[l]] -= 1
                window_length = r - l
                l += 1
                
            print(l,r, window_length)
            longest_window_length = max(longest_window_length, window_length)

        return longest_window_length


            



