class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size();

        while (l < r){
            while (!(std::isalnum(s[l]))){
                l ++;
            }
            while (!(std::isalnum(s[r]))){
                r--;
            }

            if (l < r && std::tolower(s[l]) != std::tolower(s[r])){
                return false;
            }

            l++;
            r--;
        }
        return true;
    }
};
