class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int result = 0;

        int l = 0;
        int r = 0;
        
        std::unordered_map<char, int> values;

        while (r < s.size()){

            values[s[r]] ++;

            while (l < r && values[s[r]] > 1){
                values[s[l]] --;
                l++;
            }

            result = max(result, ((r - l) + 1));
            r++;
        }

        return result;

    }
};
