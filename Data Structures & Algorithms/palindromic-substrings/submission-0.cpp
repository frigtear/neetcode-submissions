class Solution {
public:
    int countSubstrings(string s) {

        std::vector<std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
        int num_palindromes = 0;
        for (int i = s.size() - 1; i >= 0; i-- ){
            for (int j = i; j < s.size(); j++) {

                if (s[i] == s[j]) {
                    if (i == j) {
                        dp[i][j] = true;
                        num_palindromes ++;
                        continue;
                    }

                    if (j == i + 1){
                        dp[i][j] = true;
                        num_palindromes ++;
                        continue;
                    }

                    if (dp[i+1][j-1] == true){
                        dp[i][j] = true;
                        num_palindromes++; 
                    }
                }
                else {
                    continue; // No chance of a palindrome here or
                              // for future problems
                }

            }
        }

        return num_palindromes;


    }
};
