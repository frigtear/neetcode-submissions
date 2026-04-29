class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:

        def valid_fruit(x,y):
            return y >= 0 and y < len(grid) and x >= 0 and x < len(grid[y]) and grid[y][x] == 1
        
        queue = deque()
        num_fresh_oranges = 0
        for y in range(len(grid)):
            for x in range(len(grid[y])):
                if grid[y][x] == 2:
                    queue.append((x,y))
                elif grid[y][x] == 1:
                    num_fresh_oranges += 1

        if queue:
            minutes = -1
        else:
            minutes = 0
        oranges_converted = 0
        while queue:
            has_children = False
            minutes += 1
            print(minutes, queue)
            for _ in range(len(queue)):
                node = queue.popleft()
                node_x = node[0]
                node_y = node[1]
                
                if valid_fruit(node_x+1, node_y):
                    grid[node_y][node_x+1] = 2
                    oranges_converted +=1
                    queue.append((node_x+1, node_y))

                if valid_fruit(node_x-1, node_y):
                    grid[node_y][node_x-1] = 2
                    oranges_converted +=1
                    queue.append((node_x-1, node_y))

                if valid_fruit(node_x, node_y+1):
                    grid[node_y+1][node_x] = 2
                    oranges_converted +=1
                    queue.append((node_x, node_y+1))

                if valid_fruit(node_x, node_y-1):
                    grid[node_y-1][node_x] = 2
                    oranges_converted +=1
                    queue.append((node_x, node_y-1))
            
        
        print(num_fresh_oranges)
        if num_fresh_oranges > 0 and num_fresh_oranges != oranges_converted:
            return -1
        return minutes





