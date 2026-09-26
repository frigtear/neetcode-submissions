class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      

        std::unordered_map<int, std::set<int>> graph;
        std::set<int> trustless;

        for (int i = 1; i <= n; i++){
            graph[i] = {}; 
        }

        for (const auto &person : trust){
            graph[person[0]].insert(person[1]);
        }

        for (auto &[p1, p2] : graph){
            if (p2.empty()){
                trustless.insert(p1); // these are the candidates for judge
            }
        }

        for (auto &[p1, p2] : graph){
            for (int person : trustless){
                if (!p2.contains(person) && p1 != person){
                    // somone does not trust this guy so he cant be judge
                    trustless.erase(person);
                    //std::cout << person;
                }
            }
        }

        if (trustless.size() == 1){
            return *trustless.begin();
        }
        return -1;

    }
};