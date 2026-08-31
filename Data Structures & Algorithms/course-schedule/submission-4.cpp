class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::map<int, std::set<int>> graph;
        std::map<int, int> indegrees;

        for (int i = 0; i < numCourses; i++) {
            indegrees[i] = 0;
        }

        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].insert(prereq[0]);
            indegrees[prereq[0]]++;
        }


        int taken = 0;
        std::deque<int> dq;
        while (taken < numCourses){
            for (const auto &course : indegrees){
                if (course.second == 0){
                    // Course has no prereqs 
                    dq.push_back(course.first);
                    std::cout << course.first;

                }
            }

            if (dq.empty() == true){
                return false;
            }

            int size = dq.size();
            for (int i = 0; i < size; i++){
                taken++;
                int course = dq.front();
                dq.pop_front();
                for (int neighbor : graph[course]) {
                    indegrees[neighbor]--;
                }
                indegrees[course] --;
            }
        }

        return true; 


    }
};
