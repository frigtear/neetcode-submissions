class Solution {
public:
    string longestPalindrome(string s) {
        
        // ababd

        // 0 0 0 0 0
        // 0 0 0 0 0
        // 0 0 0 0 0
        // 0 0 0 0 0
        // 0 0 0 0 0

        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        int longest = 1;
        int l = 0;
        int r = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++){

                if (i == j){
                    dp[i][j] = true;
                    if (1 > longest) {
                        l = i;
                        r = j;
                        longest = 1;
                    }
                   
                    continue;
                }

                if (j == i + 1 && s[i] == s[j]){
                    dp[i][j] = true;
                    if (2 > longest) {
                        longest = 2;
                        l = i;
                        r = j;
                    }
                    
                    continue;
                }
                else if (j == i + 1){
                    continue;
                }
        
                if ( s[i] == s[j] && dp[i+1][j-1] == true){
                    dp[i][j] = true;

                    if (j - i + 1 > longest){
                        longest = j - i + 1;
                        l = i;
                        r = j;
                    }
                }
            }
        }
       // std::cout << l;
       // std::cout << r << "HELLO!";
        return s.substr(l, (r-l) + 1);

    }
};
