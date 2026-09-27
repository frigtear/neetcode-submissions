class Solution {

int getArea(int i, int j, vector<vector<int>>& grid){
    int area = 1;
    std::queue<std::pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = 2;

    static constexpr std::array<std::pair<int, int>, 4> directions = {{
    {0, 1},
    {1, 0},
    {-1, 0},
    {0, -1}
    }};

    while (!q.empty()){
        std::pair<int, int> node = q.front();
        int ai = node.first;
        int aj = node.second;
        q.pop();

        for (const auto &direction : directions) {
            int ni = ai + direction.first;
            int nj = aj + direction.second;

            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 1){
            
                grid[ni][nj] = 2;
                area ++;
                q.push({ni,nj});
            }
        }
    }

    return area;

}


public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = INT_MIN; 
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    int area = getArea(i, j, grid);
                    max_area = std::max(max_area, area);
                }
              
            }
        }

        return std::max(max_area, 0);

        
    }
};