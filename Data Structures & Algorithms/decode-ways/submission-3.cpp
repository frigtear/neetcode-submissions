class Solution {
public:
    int numDecodings(string s) {
        
        std::vector<int> dp(s.size(), 1);
        dp[0] = 1;

        if (s[0] == '0'){
            dp[0] = 0;
        }

        if (s.size() < 2){
            return dp[0];
        }

        dp[1] = 0;

        if (s[1] != '0') {
            dp[1] += dp[0];
        }

        int combined = (s[0] - '0') * 10 + (s[1] - '0');
        if (combined >= 10 && combined <= 26) {
            dp[1] += 1; 
        }

        char last_char = s[1];
        for (int i = 2; i < s.size(); i++) {
            char c = s[i];

            if (c == '0') {
                if (last_char == '1' || last_char == '2') {
                    dp[i] = dp[i-2];
                } else {
                    dp[i] = 0; 
                }
            }
            else if (last_char == '0'){
                dp[i] = dp[i-1];
            }
            else if ((last_char - '0')*10 + (c - '0') > 26){
                dp[i] = dp[i-1];
            }
            else {
                dp[i] = dp[i-1] + dp[i-2];
            }

            last_char = c;
        }
        
        return dp[s.size() - 1];

    }
};
