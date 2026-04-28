class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        def dfs(x, y):
            if x < 0 or x >= len(grid[0]) or y < 0 or y >= len(grid):
                return
            elif grid[y][x] == "1":
                grid[y][x] = "x"
                dfs(x+1,y)  
                dfs(x-1,y)
                dfs(x,y-1) 
                dfs(x,y+1)
                
                        
        islands = 0

        for y in range(len(grid)):
            for x in range(0, len(grid[0])):
            
                if grid[y][x] == "1":
                    islands += 1
                    dfs(x, y)

        return islands


