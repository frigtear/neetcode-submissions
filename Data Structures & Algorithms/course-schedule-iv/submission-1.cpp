class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, std::set<int>> prereqs;
        std::unordered_map<int, int> indegrees;
        std::queue<int> q;

        // whenever visiting a node 
        // simply mark ones it lowers indegrees of 
        // as this is prereq of that
        // then also add all the ones that are already marked as prereq
        // this works beause we have guaranteed to have visited all prereqs already

        for (size_t i = 0; i < numCourses; i++){
            indegrees[i] = 0;
            graph[i] = {};
            prereqs[i] = {};
        }

        for (const auto &prereq : prerequisites){
            graph[prereq[0]].push_back(prereq[1]);
            indegrees[prereq[1]] ++;
        }

        for (const auto& degree : indegrees){
            if (degree.second == 0){
                q.push(degree.first);
            }
        }

        while (!q.empty()){

            int val = q.front();
            q.pop();

            for (int node : graph[val]){
                std::cout << node << " " << std::endl;
                prereqs[node].insert(val);
                prereqs[node].insert(prereqs[val].begin(), prereqs[val].end());
                indegrees[node] --;
                if (indegrees[node] == 0){
                    q.push(node);
                }
            }

            
        }
        
        std::vector<bool> result;

        for (const auto& query : queries){
            result.push_back((prereqs[query[1]].contains(query[0])));
        }
        return result;

    }
};