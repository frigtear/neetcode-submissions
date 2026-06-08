class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::map<char, int>, std::vector<std::string>> anagrams;
        
        for (const std::string& str : strs){
            std::map<char, int> anagram;
            for ( char c : str ){
                anagram[c] ++;
            }
            anagrams[anagram].push_back(str);
        }

        std::vector<std::vector<string>> result;

        for (const auto& [anagram, strs] : anagrams){
            result.push_back(strs);
        }


        return result;

    }
};
