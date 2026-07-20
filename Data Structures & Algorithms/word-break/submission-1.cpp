class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (size_t i = 0; i < s.size() + 1; ++i){

            for (size_t j = 0; j <= i; ++j) {
               // std::cout <<  s.substr(j, (i-j)) << std::endl;

                if ( dp[j] == true ) {
                    for ( const auto &word : wordDict ) {
                        if ( s.substr(j, (i-j)) == word ){
                            dp[i] = true;
                        }
                    }
                }
            }
        }

       // for (int i = 0; i < dp.size(); i++) {
       //     std::cout << "dp[" << i << "] = " << std::boolalpha << dp[i] << '\n';
       // }
        return dp[s.size()] == true;
    }
};
