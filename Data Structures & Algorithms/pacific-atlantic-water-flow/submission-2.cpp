class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        std::queue<std::tuple<int, int, int>> q;
        int rows = heights.size();
        int cols = heights[0].size();  

        std::vector<std::vector<bool>> pacific(rows, std::vector<bool>(cols, false));
        std::vector<std::vector<bool>> atlantic(rows, std::vector<bool>(cols, false));

        for (int c = 0; c < cols; c++) {
            q.push({0, c, 1});              
            pacific[0][c] = true;
        }
        for (int r = 1; r < rows; r++) {    
            q.push({r, 0, 1});             
            pacific[r][0] = true;
        }

        for (int c = 0; c < cols; c++) {
            q.push({rows - 1, c, 0});        
            atlantic[rows - 1][c] = true;
        }
        for (int r = 0; r < rows - 1; r++) { 
            q.push({r, cols - 1, 0});      
            atlantic[r][cols - 1] = true;
        }

        std::vector<std::pair<int, int>> directions = {
            {0, 1},
            {1, 0},
            {-1,0},
            {0,-1}
        };

        while (!q.empty()){
            auto [r, c, isPacific] = q.front();
            q.pop();

            for (const auto& [dx, dy] : directions){
                int i = r + dy;
                int j = c + dx;

                if (i >= 0 && i < heights.size() && j >= 0 && j < heights[0].size() && heights[i][j] >= heights[r][c]){
                    if (isPacific && pacific[i][j] == false){
                        pacific[i][j] = true;
                        q.push({i, j, isPacific});
                    }
                    else if ( !isPacific && atlantic[i][j] == false){
                        atlantic[i][j] = true;
                        q.push({i, j, isPacific});
                    }
                }
            }
        }

        std::vector<std::vector<int>> result;
        for (int i = 0; i < heights.size(); i++){
            for (int j = 0; j < heights[0].size(); j++){
                if (pacific[i][j] && atlantic[i][j]){
                    result.push_back({i, j});
                }
            }
        }

        return result;

    }
};
