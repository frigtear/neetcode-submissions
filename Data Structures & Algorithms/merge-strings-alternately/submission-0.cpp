class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int l = 0;
        int r = 0;
        std::string result;

        while (r < word1.size() || l < word2.size()){
            if (r < word1.size()){
                result += word1[r];
                r++;
            }
            if (l < word2.size()){
                result += word2[l];
                l++;
            }
        }

        return result;

    }
};