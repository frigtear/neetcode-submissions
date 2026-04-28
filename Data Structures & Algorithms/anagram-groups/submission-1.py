class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = dict()
        for string in strs:
            temp = tuple(sorted(string))
            if temp in anagrams:
                anagrams[temp].append(string)
            else:
                anagrams[temp] = [string,]
        
        return anagrams.values()