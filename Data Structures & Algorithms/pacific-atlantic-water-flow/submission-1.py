class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        
        nodes = dict()

        def dfs(x:int, y:int, prev:int, is_pacific:bool) -> None:
            if y < 0 or x < 0 or y >= len(heights) or x >= len(heights[y]):
                return
            if heights[y][x] < prev:
                return

            if (y,x) in nodes:
                if is_pacific:
                    if nodes[(y,x)][0] == 0:
                        nodes[(y,x)][0] = 1
                    else:
                        return
                else:
                    if nodes[(y,x)][1] == 0:
                        nodes[(y,x)][1] = 1
                    else:
                        return
            else:
                if is_pacific:
                    nodes[(y,x)] = [1,0]
                else:
                    nodes[(y,x)] = [0,1]


            dfs(x+1,y, heights[y][x], is_pacific)
            dfs(x,y+1, heights[y][x], is_pacific)
            dfs(x-1, y, heights[y][x], is_pacific)
            dfs(x, y-1, heights[y][x], is_pacific)



        for y in range(len(heights)):
            for x in range(len(heights[y])):
                if x == 0 or y == 0:
                    dfs(x,y,0,True)
                if y == len(heights) - 1 or x == len(heights[y]) - 1:
                    dfs(x,y,0,False)

        result = list()
        for node in nodes:
            if nodes[node] == [1,1]:
                result.append(list(node))

      #  print(result)
        return result