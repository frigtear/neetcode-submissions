from collections import deque
from typing import List

class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        INF = 2147483647

        def in_bounds(x, y):
            return (
                y >= 0 and y < len(grid)
                and x >= 0 and x < len(grid[y])
                and grid[y][x] == INF
            )

        queue = deque()

        for y in range(len(grid)):
            for x in range(len(grid[y])):
                if grid[y][x] == 0:
                    queue.append((x, y))

        while queue:
            node = queue.popleft()
            ndx = node[0]
            ndy = node[1]

            for nx in range(ndx - 1, ndx + 2, 2):
                if in_bounds(nx, ndy):
                    grid[ndy][nx] = grid[ndy][ndx] + 1
                    queue.append((nx, ndy))

            for ny in range(ndy - 1, ndy + 2, 2):
                if in_bounds(ndx, ny):
                    grid[ny][ndx] = grid[ndy][ndx] + 1
                    queue.append((ndx, ny))



                    