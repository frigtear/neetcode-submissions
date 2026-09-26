class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // step 1: build a hashmap of indegrees
        // step 2: we need a queue of nodes that hit 0!!!
        std::unordered_map<int, std::vector<int>> graph;
        std::unordered_map<int, int> indegrees;
        std::queue<int> q; 

        for (size_t i = 0; i < numCourses; i++){
            indegrees[i] = 0;
        }

        for (const auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];

            indegrees[course] ++;
            graph[prereq].push_back(course);
            if (!indegrees.contains(prereq)){
                indegrees[prereq] = 0;
            }
        }

        for (const auto &course : indegrees){
            if (course.second == 0){
                q.push(course.first);
            }
        }

        // we should init the queue with no indegree stuff
        int time = 0;
        while (!q.empty()){
            int course = q.front();
            q.pop();
            time++;

            // remove from indegrees based on whats connected to this node
            for (const int course : graph[course] ){
                indegrees[course] --;
                if (indegrees[course] == 0){
                    q.push(course);
                }
            }

        }
    
        return numCourses == time;
    }
};
