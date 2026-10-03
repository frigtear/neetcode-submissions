class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        std::array<int, 256> last_seen;
        last_seen.fill(-1);

        int l = 0; 
        int r = 0;

        int result = 0;

        if (s.size() == 1){
            return 1;
        }

        while (r < s.size()){
            
    
            if (last_seen[s[r]] == -1 || (last_seen[s[r]] < l || last_seen[s[r]] > r)){
                last_seen[s[r]] = r;
            }
            else{
                l = last_seen[s[r]] + 1;
                last_seen[s[r]] = r;
            }
            

            result = max(result, ((r - l) + 1));
            r++;
        }

        return result;

    }
};
