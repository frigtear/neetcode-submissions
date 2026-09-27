class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        queue<tuple<int, int, int>> q;   // {row, col, isPacific}

        // Pacific borders
        for (int c = 0; c < cols; c++) {
            q.push({0, c, 1});
            pacific[0][c] = true;
        }
        for (int r = 1; r < rows; r++) {
            q.push({r, 0, 1});
            pacific[r][0] = true;
        }

        // Atlantic borders
        for (int c = 0; c < cols; c++) {
            q.push({rows-1, c, 0});
            atlantic[rows-1][c] = true;
        }
        for (int r = 0; r < rows-1; r++) {
            q.push({r, cols-1, 0});
            atlantic[r][cols-1] = true;
        }

        vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty()) {
            auto [r, c, isPacific] = q.front();
            q.pop();

            for (auto [dx, dy] : dirs) {
                int i = r + dy;
                int j = c + dx;

                if (i < 0 || i >= rows || j < 0 || j >= cols) continue;
                if (heights[i][j] < heights[r][c]) continue;

                if (isPacific && !pacific[i][j]) {
                    pacific[i][j] = true;
                    q.push({i, j, 1});
                }
                if (!isPacific && !atlantic[i][j]) {
                    atlantic[i][j] = true;
                    q.push({i, j, 0});
                }
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};