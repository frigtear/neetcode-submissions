class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, int> indegrees;

        for (int i = 0; i < numCourses; i++){
            graph[i] = {};
            indegrees[i] = 0;
        }

        for (const auto& prereq : prerequisites){
            indegrees[prereq[0]] ++;
            graph[prereq[1]].push_back(prereq[0]);
        }

        std::queue<int> q;

        for (const auto& indegree : indegrees){
            if (indegree.second == 0){
                q.push(indegree.first);
            }
        }

        std::vector<int> result;

        while (!q.empty()){
            
            int to_take = q.front();
            q.pop();
            result.push_back(to_take);

            for (int course : graph[to_take]){
                indegrees[course] --;
                if (indegrees[course] == 0){
                    q.push(course);
                }
            }
        }

            
            
        if (numCourses == result.size()){
            return result;
        }
        

        return {};

    }
};
