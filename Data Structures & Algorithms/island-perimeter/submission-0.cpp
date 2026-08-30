class Solution {
private:
    std::set<std::pair<int, int>> visited;
    int sum = 0;

    bool isLand(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() &&
               j >= 0 && j < grid[0].size() &&
               grid[i][j] == 1;
    }

    void helper(int i, int j, vector<vector<int>>& grid) {
        if (visited.contains({i, j}) || !isLand(i, j, grid)) {
            return;
        }

        visited.insert({i, j});

        int num_lands = 0;

        if (isLand(i + 1, j, grid)) {
            num_lands++;
        }

        if (isLand(i - 1, j, grid)) {
            num_lands++;
        }

        if (isLand(i, j + 1, grid)) {
            num_lands++;
        }

        if (isLand(i, j - 1, grid)) {
            num_lands++;
        }

        sum += 4 - num_lands;

        helper(i + 1, j, grid);
        helper(i - 1, j, grid);
        helper(i, j - 1, grid);
        helper(i, j + 1, grid);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        sum = 0;
        visited.clear();

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                helper(i, j, grid);
            }
        }

        return sum;
    }
};