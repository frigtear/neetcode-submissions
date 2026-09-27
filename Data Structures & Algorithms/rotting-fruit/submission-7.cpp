class Solution {

private:
    bool inBounds(int r, int c, const std::vector<std::vector<int>>& grid) {
        return (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size()) && grid[r][c] == 1;
}


public:
    int orangesRotting(vector<vector<int>>& grid) {
        int num_fruit = 0;
        // get all the sources add them to our queue
        std::queue<std::pair<int, int>> rotten;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2){
                    rotten.push({i, j});
                }
                if (grid[i][j] == 1){
                    num_fruit++;
                }
            }
        }

        int time = 0;
        int num_rotted = 0;

        while (!rotten.empty()){

            int level_size = rotten.size();
            for (size_t _ = 0; _ < level_size; _++){
                auto &index = rotten.front();
                int i = index.first;
                int j = index.second;

                // visit index
                if (inBounds(i+1, j, grid)){
                    num_rotted++;
                    rotten.push({i+1, j});
                    grid[i+1][j] = 2;
                }
                if (inBounds(i-1, j, grid)){
                    num_rotted++;
                    rotten.push({i-1, j});
                    grid[i-1][j] = 2;
                }
                if (inBounds(i, j+1, grid)){
                    num_rotted++;
                    rotten.push({i, j+1});
                    grid[i][j+1] = 2;
                }
                if (inBounds(i, j-1, grid)){
                    num_rotted++;
                    rotten.push({i, j-1});
                    grid[i][j-1] = 2;
                }
                rotten.pop();
            }
            time ++;

        }

        if (num_fruit != num_rotted){
            return -1;
        }

       
        if (time == 0){
            return 0;
        }

        return time - 1;


    }
};
