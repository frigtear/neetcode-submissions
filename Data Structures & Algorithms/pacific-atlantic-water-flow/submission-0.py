class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        
        pacific_reached = False
        atlantic_reached = False

        visited = set()
        result = list()

        def dfs(x, y, origin_height):
            nonlocal pacific_reached, atlantic_reached
          #  print(x,y)
            if x < 0 or y < 0: 
                pacific_reached = True
              #  print("PACIFIC_REACHED")
                return 
            elif y >= len(heights) or x >= len(heights[y]):
                atlantic_reached = True 
               # print("ATLANTIC REACHED")
                return
            elif (x,y) in visited:
                return
            elif heights[y][x] > origin_height:
                return

            height = heights[y][x]
            visited.add((x,y))

            dfs(x+1, y, height)
            dfs(x, y+1, height)
            dfs(x-1, y, height)
            dfs(x, y-1, height)
    
            



        for y in range(len(heights)):
            for x in range(len(heights[y])):
                pacific_reached = False
                atlantic_reached = False
                dfs(x, y, heights[y][x])
                visited = set()
                if pacific_reached and atlantic_reached:
                    result.append((y,x))

        return result


    
            
            
            

            
