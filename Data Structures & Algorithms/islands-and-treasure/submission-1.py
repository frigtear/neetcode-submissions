from collections import deque
from typing import List

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        
        INF = 2147483647

        def in_bounds(x,y):
            return (y >= 0 and y < len(grid) and x >= 0 and x < len(grid[y])) and grid[y][x] == 2147483647

        queue = deque()

        for y in range(len(grid)):
            for x in range(len(grid[y])):
                if grid[y][x] == 0:
                    queue.append((x,y))
                

        while queue:
            node = queue.popleft()
            node_x = node[0]
            node_y = node[1]

            for node_neighbor_x in range(node_x-1, node_x+2, 2):
                if in_bounds(node_neighbor_x, node_y):
                    grid[node_y][node_neighbor_x] = grid[node_y][node_x] + 1
                    queue.append((node_neighbor_x, node_y))

            for node_neighbor_y in range(node_y-1, node_y+2, 2):
                if in_bounds(node_x, node_neighbor_y):
                    grid[node_neighbor_y][node_x] = grid[node_y][node_x] + 1
                    queue.append((node_x, node_neighbor_y))

        

            


        



