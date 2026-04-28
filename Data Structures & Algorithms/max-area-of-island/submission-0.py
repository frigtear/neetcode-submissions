class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        
        def dfs(x, y):
            if y < 0 or y >= len(grid) or x < 0 or x >= len(grid[y]) or grid[y][x] != 1:
                return 0
            
            grid[y][x] = -1
            return 1 + dfs(x+1, y) + dfs(x-1, y) + dfs(x, y+1) + dfs(x, y-1)
            

        max_area = 0
        for y in range(len(grid)):
            for x in range(len(grid[y])):
                max_area = max(max_area, dfs(x,y))
        
        return max_area