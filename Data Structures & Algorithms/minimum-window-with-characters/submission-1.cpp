class Solution {
public:
    string minWindow(string s, string t) {
        std::map<char, int> t_chars;

        for (char c : t){
            t_chars[c]++;
        }

        int l = 0;
        int r = 0;

        std::map<char, int> window;

        string result = "";
        int shortestLength = INT_MAX;

        int validity_counter = 0;
        while (r < s.size()){

            window[s[r]] ++;
            if (t_chars.contains(s[r]) && (window[s[r]] == t_chars[s[r]])){
                validity_counter++;
            }

            while (l < r && (!t_chars.contains(s[l]) || window[s[l]] > t_chars[s[l]])) {
                window[s[l]] --;
                if (window[s[l]] <= 0){
                    window.erase(s[l]);
                }
                l++;
               
            }

            if (validity_counter >= t_chars.size() && (r - l) + 1 < shortestLength){
                shortestLength = (r - l) + 1;
                result = s.substr(l, ((r - l) + 1));
            }

            r++;
        }

        return result;
    }
};
