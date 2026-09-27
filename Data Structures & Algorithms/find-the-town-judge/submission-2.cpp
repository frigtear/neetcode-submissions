class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      
        std::unordered_map<int, int> trusted;
        std::unordered_map<int, int> trustee;

        for (size_t i = 1; i <= trust.size(); i++){
            trusted[i] = 0;
            trustee[i] = 0;
        }


        for (const auto &person : trust){
            trusted[person[1]]++;
            trustee[person[0]]++;
        }

        for (size_t i = 1; i <= n; i++){
            if (trusted[i] == (n-1) && trustee[i] == 0){
                return i;
            }
        }

        return -1;

    }
};