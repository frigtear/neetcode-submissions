class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        n = len(board)

        def hasDupes(vals):
            vals = [val for val in vals if val != "."]
            #print(vals)
            return len(vals) != len(set(vals))
        

        rows, columns, grids = list(), list(), list()
        for row in board:
            if hasDupes(row):
                return False

        for i in range(n):
            column = list()
            for row in board:
                column.append(row[i])
            if hasDupes(tuple(column)):
                return False
           
        
        # 0, 0      0, 3,      0, 6       
        # 1
  
        for i in range(0, n, 3):
            for j in range(0, n, 3):
                grid = list()
                for k in range(3):
                    grid.extend(board[i+k][j:j+3])
                #print(grid)
                if hasDupes(tuple(grid)):
                    return False
        
        return True
                

        
                
        