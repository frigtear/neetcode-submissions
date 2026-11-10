class Solution {
public:
    int countSubstrings(string s) {
        
        
        std::vector<std::vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        int substrings = s.size();
        
        // base case
        for (int i = 0; i < s.size(); i++){
            dp[i][i] = 1;
            if (i+1 < s.size()){
                if (s[i] == s[i+1]){
                    dp[i][i+1] = 1;
                    substrings ++;
                }
            }
        }

        
        for (int k = 2; k < s.size(); k++){
            for (int i = 0; i < s.size() - k; i++){
                int j = i + k;

                if (i < s.size() && j - 1 > 0 && dp[i+1][j-1] == 1 && s[i] == s[j]){
                    dp[i][j] = 1;
                    substrings++;
                }
            }
        }


/*
        for (const auto& row : dp) {
            for (int value : row) {
                std::cout << value << ' ';
            }
            std::cout << '\n';
        }
*/
        return substrings;
        // 2, 1
        // [a, b, c]
        // [d, e, f]
        // [g, h, i]

        // 11, 12, 13
        // 21, 22, 23
        // 31, 32, 33

        // 11, 22, 33
        // 12, 23
        // 13

        // width is 3, height is 3
        // i is 123, then 12, then 1
        // j is 123, 23, then 3

        // w = .size()

        // k
        // k goes from 0 to 2
        // i goes from 0 to w - k
        // j goes from k to size - 1

        

    }
};
