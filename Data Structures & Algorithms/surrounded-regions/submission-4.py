class Solution:
    def solve(self, board: List[List[str]]) -> None:
        safe = set()
     
        def dfs(x,y):
            if (x,y) in safe:
                return
            if x < 0 or y < 0 or y >= len(board) or x >= len(board[y]) or board[y][x] == "X":
                return

            safe.add((x,y))
            dfs(x+1,y)
            dfs(x,y+1)
            dfs(x-1,y)
            dfs(x,y-1)

        if len(board) <= 1 or len(board[0]) <= 1:
            return

        for x in range(0, len(board[0])+1, len(board[0]) - 1):
            for y in range(0, len(board)):
                dfs(x,y)

        for y in range(0, len(board), len(board)-1):
         
            for x in range(0, len(board[y])):
                dfs(x,y)

      # print(safe)

        for y in range(len(board)):
            for x in range(len(board[y])):
                if (x,y) not in safe and board[y][x] == "O":
                    board[y][x] = "X"


        

                
        

