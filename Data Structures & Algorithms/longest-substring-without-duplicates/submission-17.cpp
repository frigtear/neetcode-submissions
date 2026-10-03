class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::array<int, 256> last_seen;
        last_seen.fill(-1);

        int l = 0;
        int result = 0;

        for (int r = 0; r < s.size(); ++r) {
            if (last_seen[s[r]] >= l) {
                l = last_seen[s[r]] + 1;
            }

            last_seen[s[r]] = r;
            result = max(result, r - l + 1);
        }

        return result;
    }
};