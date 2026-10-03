class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int characters[257] = {};

        int l = 0; 
        int r = 0;

        int result = 0;

        while (r < s.size()){
            
            characters[s[r]] += 1;

            while (characters[s[r]] > 1){
                characters[s[l]] --;
                l++;
            }

            result = max(result, ((r - l) + 1));

            r++;
            

        }

        return result;

    }
};
