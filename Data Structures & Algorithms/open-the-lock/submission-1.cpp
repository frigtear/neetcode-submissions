class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int min_turns = INT_MAX;
        std::set<std::string> visited;
        std::queue<std::pair<std::string, int>> q;

        q.push({"0000", 0});
        visited.insert("0000");

        for (const auto& deadend : deadends){
            if (deadend == "0000"){
                return -1;
            }
            visited.insert(deadend);
        }
       

        while (!q.empty()){
            auto val = q.front();
            //std::cout << combo << " ";
            q.pop();

            if (val.first == target){
                return val.second;
            }
            else{
                
                for (size_t i = 0; i < val.first.size(); i++){
            
                    int num = val.first[i] - '0';
                    std::string combo = val.first;
                    combo[i] = ((num + 1) % 10) + '0';
                    
                    if (!visited.contains(combo)){
                        q.push({combo, val.second + 1});
                        visited.insert(combo);
                    }

                    combo = val.first;
                    combo[i] = ((num + 9) % 10) + '0';
                    if (!visited.contains(combo)){
                        q.push({combo, val.second + 1});
                        visited.insert(combo);
                    }
                }
            }
        }

        return -1;
        
    }
};