class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = dict()

        for word in strs:
            if tuple(sorted(word)) not in groups:
                groups[tuple(sorted(word))] = [word]
            else:
                groups[tuple(sorted(word))].append(word)
        
        return groups.values()