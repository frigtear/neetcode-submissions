class Solution {
public:
    bool isAnagram(string s, string t) {
        std::map<char, int> s_map;
        std::map<char, int> t_map;

        for ( char c : s ){
            s_map[c] ++;
        }

        for ( char c : t ){
            t_map[c] ++;
        }
/*
        for (std::pair<char, int> vals : s_map){
            std::cout << vals.first << " " << vals.second << std::endl;
        }

        for (std::pair<char, int> vals : t_map){
            std::cout << vals.first << " " << vals.second << std::endl;
        }
*/
        return s_map == t_map;
    }
};
