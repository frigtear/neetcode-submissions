class Solution {




public:
    int orangesRotting(vector<vector<int>>& grid) {

        std::queue<std::pair<int,int>> q;
        int num_fruit = 0;

        for (size_t i = 0; i < grid.size(); i++){
            for (size_t j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    num_fruit++;
                }
                else if (grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }       

        std::vector<std::pair<int, int>> directions = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
        };

        int num_rotted = 0;
        int time = 0;
        while (!q.empty()){
            size_t level_size = q.size();
            time += 1;

            for (size_t _ = 0; _ < level_size; _++){
                
                std::pair<int, int> toVisit = q.front();
                int i = toVisit.first;
                int j = toVisit.second;
                q.pop();

                for (const auto& direction : directions){
                    int ni = i + direction.first;
                    int nj = j + direction.second;
                    if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 1){
                        num_rotted ++;
                        grid[ni][nj] = 2;
                        q.push({ni,nj});
                    }
                }
            }
        } 

        if (num_rotted != num_fruit){
            return -1;
        }
        if (time == 0){
            return 0;
        }
        return time - 1;

    }
};
